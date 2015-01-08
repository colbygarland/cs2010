/***
*
*	Author: Colby Garland
*	ID#: 5034957
*	Lab: Lab Assignment #4
*	Purpose: Simulate memory management using a class
*	File 1 of 2
*
***/

#include "memory.h"

extern int numWords; // number of words for the memory block
extern vector<int> mem_list; // list for memory blocks

/***** CONSTRUCTORS *****/
/* default constructor */
memory::memory(){
	numWords = 100;
	mem_list.resize(numWords);
}

/* constructor that takes an integer to define memory size */
memory::memory(int words){ 
	numWords = words;
	mem_list.resize(numWords);
}

/***** METHODS *****/
/* store an integer at any memory location */
void memory::store_integer(int memory_loc, int integer){

	vector<int>::iterator it;
	it = mem_list.begin();

	mem_list.insert(it + memory_loc, integer);
} 

/* get numwords */
int memory::get_capacity() const{
	return numWords;
}

/* get an integer at any given memory location */
int memory::get_integer(int memory_loc){
	return mem_list[memory_loc];
}

/* copy a block of memory to a different place in memory */
void memory::block_copy(int source, int destination, int number_elements){
	vector<int> tmp(mem_list);
	for (int i = destination; i < number_elements+destination; i++){
		tmp[i] = mem_list[source];
		source++;
	}
	mem_list = tmp;
}

/* dumps a range of memory */   
void memory::dump_memory(int start, int end) const{
	printf("       ");
	for (int i = 0; i < 10; i++) printf("%6d", i);
	printf("\n");

	int numCol = 10;	

	for (int i = start; i < end; i+=numCol){
		printf("%5d : ", i);
		for (int j = i; j < numCol+i; j++) printf("%05d ", mem_list[j]);
		printf("\n");
	}
}

/* dump all of memory */
void memory::dump_memory() const{
	dump_memory(0, numWords);
}

/***** OVERLOADED OPERATORS *****/

/* adds two memories together */
memory memory::operator+(memory m){
	for (int i = 0; i < numWords; i++) m[i] = mem_list[i] + m[i];
	return m;
}

/* check and see if two memories are equal */
bool memory::operator==(memory m){
	bool check = false;
	for (int i = 0; i < numWords; i++){
		if (mem_list[i] == m.get_integer(i)) check = true;
		else return false;
	}
	return true;
}

/* get value at location */
int& memory::operator[](int location){
	return mem_list[location];
}

/* assignment */
memory memory::operator=(memory m){
	for (int i = 0; i < numWords; i++){
		mem_list[i] = m[i];
	}
	numWords = m.numWords;
	
	for (int i = 0; i < numWords; i++){
		m[i] = mem_list[i];
	}
	return m;
}

/* overload the out operator to dump easier */
ostream & operator<<(ostream &s, const memory &m){
	m.dump_memory();
	return s;
}
