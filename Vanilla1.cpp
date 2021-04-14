#include "StdAfx.h"
#include "Vanilla1.h"


VanillaOption1::VanillaOption1(PayOff& ThePayOff_, double Expiry_) : ThePayOff(ThePayOff_), Expiry(Expiry_)
{

}


double VanillaOption1::GetExpiry() const 
{
	return Expiry;
}

double VanillaOption1::OptionPayOff(double Spot) const
{
	return ThePayOff(Spot);
}
