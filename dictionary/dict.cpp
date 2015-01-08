#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

/* 

	Author: Colby Garland ID# 5034957
	Assignment #1: Dictionary
	Purpose: Create a dictionary from a specified file without using strings. It reads from a file 
		 specified by using the < operator in the command line. Example: "./prog < FILE". It 
		 reads characters from the file and creates the words to put into the dictionary.
	File # 1 of 1 (no other cpp files for this project)

*/

const int NUMWORD = 10; // max number of words
const int WORDSIZE = 132; // max word length
char dictionary [NUMWORD][WORDSIZE] = {0};
int freq [NUMWORD] = {0}; // frequency of each word array
int ptr = 0; // points to current word in dictionary
int letterPtr = 0;
int freqPtr = 0;

/* FUNCTION PROTOTYPES */
int StrLength(int); /* find the length */
void print();       /* dumps the dictionary */
int strcmp();	    /* compares to see if word already in dictionary */

/* 
	finds the length of the specified word, returns j which is the length
*/
int strLength(int input){
	int j = 0;
	while (dictionary[input][j] != 0) j++;
	if (j > WORDSIZE) j = WORDSIZE;
	return j;
}


/*
	prints out the dictionary
	error checking for length is in here
	also tells the user of the restrictions of the dictionary
*/
void print(){ 
	int letter = 0;
	cout << "--------------DICTIONARY--------------\n";
	cout << "Can only hold up to " << NUMWORD << " words.\n";
	cout << "Can only read words up to " << WORDSIZE << " letters.\n" << endl;
	if (ptr > NUMWORD) {
		cout << "NOTE - Too many words in dictionary\nNOTE - Printing out up to " << NUMWORD << endl << endl;
		ptr = NUMWORD;
	}
	cout << "Word         Frequency\n";
	cout << "-----------------------\n";
	for (int i = 0; i < ptr; i++){
		for (letter = 0; letter < WORDSIZE; letter++){
			if (dictionary[i][letter] != 0){
				cout << dictionary[i][letter];
				if (strLength(ptr) >= WORDSIZE) break;
			}
		}
		if (dictionary[i][letter] != 0) {
			if (freq[i] == 0) freq[i]++;
			cout << " 	      " << freq[i] << "	  		    " <<  endl;
		}
		if (strLength(i) >= WORDSIZE) cout << "NOTE - The word has been cut off because it is longer than the allowed wordsize" << endl;
		if (freq[i] == 1) freq[i]--;
	}
	cout << endl;
}

/* 
	compares the word against what is already in the dictionary
	returns 1 if found, 0 if not found
*/
int strcmp() { 
	bool word = false;
	for (int i = 0; i < ptr; i++){
		for (int j = 0; j < strLength(ptr-1); j++){
			if (dictionary[i][j] == dictionary[ptr][j]){
				word = true;
			} else {				
				word = false;
				break;
			}
		}
		if (word){
			for (int k = 0; k < WORDSIZE; k++) dictionary[ptr][k] = 0;
			ptr--;
			freq[i] +=1;			
			return 1;
		}	
	}
	return 0;
}

int main() {

	char ch;
	while( cin.good() ) {

 		ch = cin.get();			
 		if ( isalpha(ch) ) {				
       			if (ch > 64 && ch <= 90) ch += 32; // converts upper to lower case
			dictionary[ptr][letterPtr] = ch;
			letterPtr++;		
    		} else  if (ch == ' ' || ch == '\n'){ // if a space or new line, inc ptr to start new word
			if (strcmp() == 1){ // if the word is already in dictionary, inc frequency
				freq[freqPtr] += 1;
				freqPtr++;	
			}	
			ptr++;	
			letterPtr = 0;		
		}

	}
	print(); // dump dictionary
 	return 0;
	
}
