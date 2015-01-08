/*
	Author: Colby Garland ID# 5034957
	Purpose: Using structs and dynamic memory allocation, implement ANOTHER dictionary.
	File 1 of 2
*/

#include "dictionary.h"

BOOL InsertWord(DICT &dict, WORD word){
/* 
  adds word to dictionary , if word can't be added returns false else returns true
*/
	if (FullDictionary(dict)) return false;

	ENTRY *ptr = new ENTRY;

        ptr->count = 1;

	ptr->w = word;
        ptr->nextWord = dict.Words;

	dict.Words = ptr;
	dict.numWords++;

	return true;
}

void DumpDictionary(DICT &dict) {
/* 
  will sort the dictionary, and display the contents
*/
	ENTRY *ptr = dict.Words;

	sort(ptr->w.begin(), ptr->w.end()); // sorts the entries

	cout << "---------------DICTIONARY---------------\n";
	cout << "WORD--------------FREQ\n";
	
	for (int i = 0; i < dict.numWords; i++){
		cout << ptr->w << "		";
		cout << ptr->count << endl;
		ptr = ptr->nextWord;
	}
}

WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or empty string if no more words in input stream
*/
	BOOL in = false;
	WORD myString;
	char ch;
	while( cin.good() ) {
		ch = cin.get();
		if ( isalpha(ch) ) {
			if (ch > 64 && ch <= 90) ch += 32; // converts upper to lower case
			myString.push_back(ch);
			in = true; // a character did go in
		}
		else if (in) return myString;
	}
	return "";
}

BOOL FullDictionary(DICT &dict) {
/* 
   if dictionary is full, return true else false 
*/
	if (dict.numWords == MAX) return true;
	else return false;
}

ENTRY *LocateWord(DICT &dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns pointer to entry else returns  0
*/
	ENTRY *ptr = dict.Words;
	for (int i = 0; i < dict.numWords; i++){
 		if (ptr->w == word) return ptr;
		ptr = ptr->nextWord;
	}
	return NULL;
}
