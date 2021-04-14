/*
AntiThetic.cpp
Arrays.cpp
ConvergeneTable.cpp
ExoticBSEnginer.cpp
ExoticEnginer.cpp
MCStatistics.cpp
Normals.cpp
Parameters.cpp,
ParkMiller.cpp,
PathDependent.cpp
PathDependentAsian.cpp
PayOff3.cpp
PayOffBridge.cpp
Random2.cpp
*/

using namespace std;
#include "main.h"
#include "ParkMiller.h"
#include <iostream>
#include "StatisticsMC.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"
#include "PathDependentAsian.h"
#include "ExoticBSEngine.h"


int EquityFXMainDemo()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	double d;
	unsigned NumberOfDates;
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

	cout << "\nd\n";
	cin >> d;

	cout << "Number of dates\n";
	cin >> NumberOfDates;

	cout << "\nNumber of paths e.g. 1000\n";
	cin >> NumberOfPaths;

	PayOffPut thePayOff(Strike);
	MJArray times(NumberOfDates);

	for (unsigned long i=0; i < NumberOfDates; i++)
		times[i] = (i+1.0)*Expiry/NumberOfDates;

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);
	ParametersConstant dParam(d);

	PathDependentAsian theOption(times, Expiry, thePayOff);
	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(NumberOfDates);
	AntiThetic GenTwo(generator);

	ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

	theEngine.DoSimulation(gathererTwo, NumberOfPaths);

	vector<vector<double>> results = gathererTwo.GetResultsSoFar();
	cout <<"\nFor the asian call price the results are \n";

	for (unsigned long i=0; i<results.size(); i++)
	{
		for(unsigned long j=0; j< results[i].size(); j++)
			cout << results[i][j] << " ";
		cout << "\n";
	}

	double tmp;
	cin >> tmp;
	return 0;
}