/* requires	
	PayOff3.cpp
	Random1.cpp
	SimpleMC5.cpp
	Vanilla3.cpp
	PayOffBridge.cpp
*/
#include "stdafx.h"
#include "SimpleMC5.h"
#include <iostream>
using namespace std;
#include "Vanilla3.h"

int main_______()
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

	PayOffCall thePayOff(Strike);	
	PayOffBridge thePayOffBridge(thePayOff);
	VanillaOption theOption(thePayOffBridge, Expiry);
	
	double result = SimpleMonteCarlo3(theOption,											
											Spot,
											Vol,
											r,
											NumberOfPaths);

	cout << "the price is " << result;								

	double tmp;
	cin >> tmp;
	return 0;
}
