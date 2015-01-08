// Program written by Colby Garland to find area needed to paint
// rounds up gallons to nearest gallon to sell

#include <iostream>
#include <math.h>
using namespace std;

// this function calculates the area
float area(float length, float width){
	float area = 0;
	area = length * width;
	return area;
}

// this function is the money maker; calcualates how many gallons you need
float gallon(float area, float square_feet){
	float gallon = 0;
	gallon = ceil(area / square_feet);
	return gallon;
}


int main (void) {

	float length = 0, width = 0, square_feet = 0, area1 = 0, gallon1 = 0;

	cout << "Enter the length of your wall: ";
	cin >> length;
	cout << "Enter the width of your wall: ";
	cin >> width;
	cout << "Enter how many square feet per gallon you wish: ";
	cin >> square_feet;

	area1 = area(length, width);
	gallon1 = gallon(area1, square_feet);

	cout << "You require " << gallon1 << " gallons of paint\n";

	return 0;
}

