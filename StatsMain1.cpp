
/* requires	
	MCStatistics.cpp
	Parameters.cpp
	PayOff3.cpp	
	Random1.cpp
	SimpleMC7.cpp
	Vanilla3.cpp
	PayOffBridge.cpp
*/
#include "stdafx.h"
#include "SimpleMC7.h"
#include "Main.h"
#include <iostream>
using namespace std;
#include "Vanilla3.h"
#include "StatisticsMC.h"

int SimpleMCDemo7()
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

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);
	
	StatisticsMean gatherer;

	SimpleMonteCarlo5(theOption,											
							Spot,
							VolParam,
							rParam,
							NumberOfPaths,
							gatherer);

	vector<vector<double>> results = gatherer.GetResultsSoFar();

	cout << "the prices are:\n ";								

	for (unsigned long i = 0; i < results.size(); ++i)
	{
		for (unsigned long j=0; j < results[i].size(); ++j)
		{
			cout << results[i][j] << " ";
		}

		cout << "\n";
	}

	double tmp;
	cin >> tmp;
	return 0;
}
