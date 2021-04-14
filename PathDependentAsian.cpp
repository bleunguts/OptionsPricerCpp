#include "StdAfx.h"
#include "PathDependentAsian.h"


PathDependentAsian::PathDependentAsian(const MJArray& LookAtTimes_, double DeliveryTime_, const PayOffBridge& ThePayOff_)
	: PathDependent(LookAtTimes_),
	DeliveryTime(DeliveryTime_),
	ThePayOff(ThePayOff_),
	NumberOfTimes(LookAtTimes_.size())
{
}

unsigned long PathDependentAsian::MaxNumberOfCashFlows() const
{
	return 1;
}

MJArray PathDependentAsian::PossibleCashFlowTimes() const
{
	MJArray tmp(1);
	tmp[0] = DeliveryTime;
	return tmp;
}

unsigned long PathDependentAsian::CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedFlows) const
{
	double sum = SpotValues.sum();
	double mean = sum/NumberOfTimes;
	GeneratedFlows[0].TimeIndex = 0;
	GeneratedFlows[0].Amount = ThePayOff(mean);

	return 1;
}

PathDependent* PathDependentAsian::clone() const
{
	return new PathDependentAsian(*this);
}