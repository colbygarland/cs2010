#include "stack.h"
#include "queue.h"

int main(){

// stack testing
	cout << "-------------Stack Testing-------------\n";

	stack s;
	
/*
*   Check and see if the stack is empty
*/
	if (s.empty()) cout << "S is empty.\n";
	else cout << "not working\n";

/*
*   Add to the stack 0 to 99
*/
	for (int i = 0; i < 100; i++) s.store(i);

/*
*   Remove from the stack. Should be 99, 98, etc
*/
	for (int i = 0; i < 5; i++) cout << s.retrieve() << " ";

/*
*   Check and see if the stack is full - it is now because n = 100 elements
*/
	if (s.full()) cout << "\nS is full.\n";
	else cout << "not working\n";

// queue testing
	cout << "\n\n-------------Queue Testing-------------\n";
	
	queue q;
/*
*   Check and see if the queue is empty
*/
	if (q.empty()) cout << "Q is empty.\n";
	else cout << "not working\n";

/*
*   Add to the queue 0 to 99
*/
	for (int i = 0; i < 100; i++) q.store(i);

/*
*   Remove from the queue. Should be 0, 1, etc
*/
	for (int i = 0; i < 5; i++) cout << q.retrieve() << " ";

/*
*   Check and see if the queue is full - it is now because n = 100 elements
*/
	if (q.full()) cout << "\nQ is full.\n";
	else cout << "\nnot working\n";

	return 0;
}
