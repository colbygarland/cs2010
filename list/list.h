/*
*	Author: Colby Garland
*	Purpose: Implement stack and queue by deriving from base class "list".
*	Contents: List header file.
*/

#ifndef LIST_H
#define LIST_H

#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class list {
	protected:      
     	vector <int> p; 
		int n;  
	public :
     	list() 
     	{ 
			n = 100;
       		p.resize(n);   
     	}
     	virtual bool empty() = 0;
     	virtual bool full() = 0;
     	virtual void store(int val) = 0;
     	virtual  int retrieve() = 0;
};


#endif
