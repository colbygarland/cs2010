/* 	
	file 1 of 1
	Colby Garland's lab 3 craps game
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int count_of_throws, die_num1, die_num2, sum, point = 0;

int die(){
	int num = 0;	
	num = rand() % 6 + 1;
	return num;
}

int roll(){
	int num_array [2];
	num_array[0] = die();
	num_array[1] = die();
	return *num_array;
}

void playGame(){
	die_num1, die_num2, sum = 0;
	srand(time(0));
	while(true){

		die_num1 = die();
		die_num2 = die();

		sum = die_num1 + die_num2;

		if (count_of_throws == 0 && sum == 7 || sum == 11){ 
			// first throw, get 7 or 11, you win
			cout << "Player rolled " << die_num1 << " + " << die_num2 << " = " << sum << "\n";
			cout << "Player wins!\n";
			break;
		} else if (sum == 2 || sum == 3 || sum == 12 && count_of_throws == 0){ 
			// first throw, get 2, 3, 12, you lose
			cout << "Player rolled " << die_num1 << " + " << die_num2 << " = " << sum << "\n";	
			cout << "Player loses; House wins!\n";
			break;
		} else {
			count_of_throws = count_of_throws + 1;
			cout << "Player rolled " << die_num1 << " + " << die_num2 << " = " << sum << "\n";
			if (sum == 7){
				cout << "Player rolled a 7; player loses!\n";
				break;
			}
			cout << "Point is " << sum << "\n";
			if (sum == point && die_num1 != 7 && die_num2 != 7){
				cout << "Player wins!\n";
				break;
			}
			point = sum;
		}
	}
	

}

int main() {
  count_of_throws = 0;
  char ans;
  bool done = true;
  while (done) {
         playGame();   // YOU MUST WRITE THIS FUNCTION
         cout << "------- Play again (y/n) ? --------";
         cin >> ans;
         if ( ans == 'y' || ans == 'Y') {
	done = true;
	count_of_throws = 0;
	}
             else done = false;
	point = 0;
  }
  return 0;
}
