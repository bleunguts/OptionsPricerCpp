/* requires
	DoubleDigital.cpp
	PayOff2.cpp
	Random1.cpp
	SimpleMC3.cpp
	Vanilla1.cpp
*/
#include "stdafx.h"
#include "SimpleMC3.h"
#include <iostream>
using namespace std;
#include "Vanilla1.h"


int main_____()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long  NumberOfPaths;
	cout << "\nEnter expiry e.g. 0.25 (time to expire)\n";
	cin >> Expiry;
	
	cout << "\nEnter strike e.g. 200 \n";
	cin >> Strike;

	cout << "\nEnter spot e.g. 195 \n";
	cin >> Spot;

	cout << "\nEnter vol e.g. 0.30 \n";
	cin >> Vol;
	
	cout << "\nr (risk free rate) e.g. 0.05 \n";
	cin >> r;

	cout << "\nNumber of paths e.g. 1000\n";
	cin >> NumberOfPaths;

	PayOff* thePayOff = new PayOffCall(Strike);
	VanillaOption1 theOption(*thePayOff, Expiry);
	
	double result = SimpleMonteCarlo3b(theOption,											
											Spot,
											Vol,
											r,
											NumberOfPaths);

	cout << "the price is " << result;							

	delete thePayOff;

	double tmp;
	cin >> tmp;
	return 0;
}
