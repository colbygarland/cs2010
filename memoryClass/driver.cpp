/***
*
*	Author: Colby Garland
*	ID#: 5034957
*	Lab: Lab Assignment #4
*	Purpose: Driver program to test the memory class
*	File 2 of 2
*
***/

#include "memory.h"

int main(void){

	memory m(100);
	memory n(100);

	for (int i = 0; i < m.get_capacity(); i++) m[i] = 1;
	n = m;

	cout << "M:"<< endl << m;
	cout <<"N:" << endl << n;

	n = n + m;
	cout <<"N = N + M"<< endl << n;
	cout << m;
	
	if (n == m) cout << "They are equal\n";
	else cout << "They are NOT equal\n";

	m[0] = 666;
	cout << m;
	cout <<endl << m[1] << endl;

	return 0;
}
