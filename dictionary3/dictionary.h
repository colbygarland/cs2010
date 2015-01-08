#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
using std::string;

const int MAX = 100;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;  

typedef struct entry {
      int count;               
      WORD w;                    
      struct entry *nextWord;   
} ENTRY;

typedef struct dict {
     int maxEntries;	     
     int numWords;            
     ENTRY *Words;            
} DICT;

ENTRY *LocateWord(DICT& , WORD); // locates the word, returns word is located
BOOL FullDictionary(DICT&);      // returns true if dictionary full, false if not
BOOL InsertWord(DICT&,WORD);     // returns a true if word inserted
WORD GetNextWord(void);          // returns the next word in the file
void DumpDictionary(DICT&);      // prints the sorted dictionary

#endif               
