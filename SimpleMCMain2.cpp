/*
requires
PayOff1.cpp
Random1.cpp
SimpleMC.cpp
*/
#include "Stdafx.h"
#include "SimpleMC.h"
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
int SimpleMCDemo2()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long  NumberOfPaths;
	cout << "\nEnter expiry\n";
	cin >> Expiry;
	
	cout << "nEnter strike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;
	
	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	PayOff callPayOff(Strike, PayOff::call);
	PayOff putPayOff(Strike, PayOff::put);

	double resultCall = SimpleMonteCarlo2(callPayOff,
											Expiry,
											Spot,
											Vol,
											r,
											NumberOfPaths);
	double resultPut = SimpleMonteCarlo2(putPayOff,
											Expiry,
											Spot,
											Vol,
											r,
											NumberOfPaths);

	cout << "the prices are " << resultCall
								<< " for the call and "
								<< resultPut
								<< " for the put\n";

	double tmp;
	cin >> tmp;

	return 0;
}
