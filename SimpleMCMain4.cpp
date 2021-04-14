/*
requires
	PayOff2.cpp
	Random1.cpp
	SimpleMC2.cpp
*/
#include "stdafx.h"
#include "SimpleMC2.h"
#include <iostream>
using namespace std;

// real numbers example http://financetrain.com/option-pricing-using-monte-carlo-simulation/
// expiry = 0.25 (time to expire)
// strike = 200 
// spot = 195
// vol = 0.30 
// r = 0.05 (risk free rate)
// n = 1000 paths
// Result 10.5126 / 12.739
int main____()
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

	unsigned long optionType;

	cout << "\nEnter 0 for call, otherwise any other key for put\n";
	cin >> optionType;

	PayOff2* thePayOffPtr;
	if (optionType == 0)
	{
		thePayOffPtr = new PayOffCall2(Strike);
	}
	else
	{
		thePayOffPtr = new PayOffPut2(Strike);
	}

	double result = SimpleMonteCarlo2a(*thePayOffPtr,
											Expiry,
											Spot,
											Vol,
											r,
											NumberOfPaths);

	cout << "the price is " << result;							

	double tmp;
	cin >> tmp;

	delete thePayOffPtr;
	return 0;
}