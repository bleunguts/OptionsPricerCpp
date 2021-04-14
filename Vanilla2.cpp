#include "stdafx.h"
#include "Vanilla2.h"

VanillaOption2::VanillaOption2(const PayOff& ThePayOff_, double Expiry_) : Expiry(Expiry_)
{
	ThePayOffPtr = ThePayOff_.clone();
}


double VanillaOption2::GetExpiry() const 
{
	return Expiry;
}

double VanillaOption2::OptionPayOff(double Spot) const
{
	return (*ThePayOffPtr)(Spot);
}

VanillaOption2::VanillaOption2(const VanillaOption2& original)
{
	Expiry = original.Expiry;
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

VanillaOption2& VanillaOption2::operator=(const VanillaOption2& original)
{
	if ( this != &original )
	{
		Expiry = original.Expiry;
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}

	return *this;
}


VanillaOption2::~VanillaOption2()
{
	delete ThePayOffPtr;
}

