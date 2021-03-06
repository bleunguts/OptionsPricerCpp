#include "stdafx.h"
#include "Random1.h"
#include "SimpleMC7.h"
#include <cmath>

void SimpleMonteCarlo5(const VanillaOption& TheOption,
						double Spot,
						const Parameters& Vol,
						const Parameters& r,
						unsigned long NumberOfPaths,
						StatisticsMC& gatherer)
{
	double Expiry = TheOption.GetExpiry();
	double variance = Vol.IntegralSquare(0, Expiry);
	double rootVariance = sqrt (variance);
	double itoCorrection = -0.5*variance;
	double movedSpot = Spot*exp(r.Integral(0,Expiry)+itoCorrection);
	double thisSpot;
	double discounting = exp(-r.Integral(0, Expiry));

	for(unsigned long i=0; i<NumberOfPaths; i++)
	{
		double thisGuassian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp(rootVariance*thisGuassian);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
		gatherer.DumpOneResult(thisPayOff * discounting);
	}
	return;
}