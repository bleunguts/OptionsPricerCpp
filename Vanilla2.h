#pragma once

#include "PayOff3.h"

class VanillaOption2
{
public:
	VanillaOption2(const PayOff& ThePayOff_, double Expiry_);
	VanillaOption2(const VanillaOption2& original);
	VanillaOption2& operator=(const VanillaOption2& original);
	~VanillaOption2();

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;
private:
	double Expiry;
	PayOff* ThePayOffPtr;
};