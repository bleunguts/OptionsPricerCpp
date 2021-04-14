/*
requires
	PayOff2.cpp
	Random1.cpp
	SimpleMC2.cpp
*/
#include "stdafx.h"
#include "SimpleMC2.h"
#include "Main.h"
#include <iostream>
using namespace std;

int SimpleMCDemo3()
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

	PayOffCall2 callPayOff(Strike);
	PayOffPut2 putPayOff(Strike);

	double resultCall = SimpleMonteCarlo2a(callPayOff,
											Expiry,
											Spot,
											Vol,
											r,
											NumberOfPaths);
	double resultPut = SimpleMonteCarlo2a(putPayOff,
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