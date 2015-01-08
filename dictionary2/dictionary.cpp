#include "dictionary.h"

/*

	Author: Colby Garland id# 5034957
	Lab #5 Assignment 2
	Purpose: Using strings, create a dictionary that reads from a file and sorts
	into an array the words
	File 1 of 2

*/

extern int ptr;
extern int counter;
extern int myCount[MAX];
extern DICT dictionary;
const int charLength = 16; // max length of characters in a string
WORD tmp;

BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

	if (FullDictionary(dict)) return 0;
	
	dict[ptr] = word;
        myCount[ptr] = 1;

	ptr++;
	return 1;

}

void DumpDictionary(DICT dict, int count[]) {
/* 
  will sort the dictionary, and display the contents
*/
	
	int charsLeft = 0; // number of characters left when string is too long


	// this is supposed to sort the dictionary, however does not work properly :(
	int i, j;
	WORD tmp;
	for (i = 1; i < MAX; i++){
		j = 1;
		while (j > 0 && dict[j - 1] > dict[j]){
			tmp = dict[j];
			dict[j] = dict[j - 1];
			dict[j - 1] = tmp;
			j--;
		}
	}

	cout << "------------DICTIONARY------------\n";
	cout << "WORD-----------FREQ\n" ;
      
	for (int i = 0; i < ptr; i++){
		if (dict[i].length() < charLength){ 
			cout << dict[i] << "		";
			cout << count[i] << endl;
		} else {
			for (int j = 0; j < charLength; j++) cout << dict[i][j];
			charsLeft = dict[i].length() - charLength;
			printf("(%d)", charsLeft);
			cout << "	" << count[i] << endl;
		  }
		  
	}

}

WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or NULL if no more words in input stream
*/

	BOOL in = 0;
	WORD myString;
	char ch;
	while( cin.good() ) {

 		ch = cin.get();			
 		if ( isalpha(ch) ) {				
       			if (ch > 64 && ch <= 90) ch += 32; // converts upper to lower case
			myString.push_back(ch);
			in = 1; // a character did go in
		}
		else if (in){
 			return myString;
		}
	}

	return "";

}


BOOL FullDictionary(DICT dict) {
/* 
   if dictionary is full, return 1 else 0 
 */
	if (ptr >= MAX) return 1;
	else return 0;
}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/

	for (int i = 0; i < ptr; i++) if (dict[i] == word) return i;
	return -1;
}

