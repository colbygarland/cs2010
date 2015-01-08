/*
*	Author: Colby Garland
*	Purpose: Implement stack and queue by deriving from base class "list".
*	Contents: Stack header file.
*/

#ifndef STACK_H
#define STACK_H

#include "list.h"

class stack : public list{
	public:
     	stack();

		bool empty();
   	 	bool full();
    	void store(int);
    	int retrieve();
};

#endif
