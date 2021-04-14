#pragma once

#include "Vanilla1.h"

double SimpleMonteCarlo3b(const VanillaOption1& TheOption,
							double Spot,
							double Vol,
							double r,
							unsigned long NumberOfPaths);