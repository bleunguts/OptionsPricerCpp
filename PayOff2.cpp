#include "stdafx.h"
#include "PayOff2.h"
#include <minmax.h>

PayOffCall2::PayOffCall2(double Strike_) : Strike(Strike_)
{
	Strike = Strike_;
}

PayOffPut2::PayOffPut2(double Strike_) : Strike(Strike_)
{
	Strike = Strike_;
}

double PayOffCall2::operator() (double Spot) const
{
	return max(Spot-Strike, 0.0);
}

double PayOffPut2::operator() (double Spot) const
{
	return max(Strike-Spot, 0.0);
}

