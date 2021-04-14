#include "stdafx.h"
#include "SimpleMC4.h"
#include "Random1.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif 

double SimpleMonteCarlo3a(const VanillaOption2& TheOption,
							double Spot,
							double Vol,
							double r,
							unsigned long NumberOfPaths)
{
	double Expiry = TheOption.GetExpiry();

	double variance = Vol*Vol*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot = Spot*exp(r*Expiry + itoCorrection);
	double thisSpot;
	double runningSum=0;

	for (unsigned long i=0; i < NumberOfPaths; ++i)
	{
		double thisGuassian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp( rootVariance*thisGuassian );
		double thisPayoff = TheOption.OptionPayOff(thisSpot);
		runningSum += thisPayoff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;

}