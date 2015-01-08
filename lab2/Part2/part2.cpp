// Program written by Colby Garland to find roots using quadratic equation

#include <iostream>
#include <math.h>
using namespace std;

// this function returns the positive root of the equation
double pos_quadratic (int a, int b, int c){
	double x = 0;
	b = b * (-1);
	x = (b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	return x;
}

// this function returns the negative root of the equation
double neg_quadratic (int a, int b, int c){
	double x = 0;
	b = b * (-1);
	x = (b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	return x;
}

int main (void) {

	int a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0;

	cout << "Enter three coefficients a, b, and c.\n";
	cout << "A = ";
	cin >> a;
	cout << "B = ";
	cin >> b;
	cout << "C = ";
	cin >> c;
	x1 = pos_quadratic(a,b,c);
	x2 = neg_quadratic(a,b,c);
	cout << "\nThe roots are = " << x1 << ", " << x2 << "\n";

	return 0;
}
