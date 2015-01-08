/*
*	Author: Colby Garland
*	Purpose: Implement stack and queue by deriving from base class "list".
*	Contents: Queue header file.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

class queue : public list{
	public:
     	queue();

		bool empty();
    	bool full();
    	void store(int);
    	int retrieve();
};

#endif
