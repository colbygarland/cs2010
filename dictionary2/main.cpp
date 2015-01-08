#include "dictionary.h"

/*

	Author: Colby Garland id# 5034957
	Lab #5 Assignment 2
	Purpose: Using strings, create a dictionary that reads from a file and sorts
	into an array the words
	File 2 of 2

*/


/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int myCount[MAX];   //tracks word frequencies
int ptr;          //keeps track of current word

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( 0 == word.length() )  {
           DumpDictionary(dictionary,myCount);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) {
           myCount[pos]++;
       }
       else if (!InsertWord(dictionary,word)) cout << "--Dictionary full, " << word << " cannot be added--\n";
	
    }
    return 0;
}
