/***
*
*	Author: Colby Garland
*	ID#: 5034957
*	Lab: Lab Assignment #5
*	Purpose: Simulate memory management using a class
*
***/

#ifndef MEMORY
#define MEMORY

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class memory {

   private:
	int numWords; // number of words for the memory block
	vector<int> mem_list; // list for memory blocks

   public:
	memory(int); // constructor that takes an integer to define memory size
	memory();    // default constructor

	void store_integer(int, int); // store an integer at any memory location
	int get_integer(int);    // retrieve an integer from any given memory location
	void block_copy(int, int, int); // source, destination, number of elements
	void dump_memory() const;           // dumps all memory
	void dump_memory(int, int) const;   // dumps a range of memory
	int get_capacity() const; // get numwords

	memory operator+(memory); // add two memories together
	bool operator==(memory); // see if two memories are equal
	int& operator[](int); // get value at location
	memory operator=(memory); // assignment	
};

ostream & operator<<(ostream &, const memory &); // dumps


#endif
