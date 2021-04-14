#pragma once
#include "PayOff2.h"

double SimpleMonteCarlo2a(const PayOff2& thePayOff,
						double Expiry,
						double Spot,
						double Vol,
						double r,
						unsigned long NumberOfPaths);
