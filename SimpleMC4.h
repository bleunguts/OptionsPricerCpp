#pragma once

#include "Vanilla2.h"

double SimpleMonteCarlo3a(const VanillaOption2& TheOption,
							double Spot,
							double Vol,
							double r,
							unsigned long NumberOfPaths);