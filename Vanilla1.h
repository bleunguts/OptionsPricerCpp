#pragma once

#include "PayOff3.h"

class VanillaOption1
{
public:
	VanillaOption1(PayOff& ThePayOff_, double Expiry_);
	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private: 
	double Expiry;
	PayOff& ThePayOff;
};

