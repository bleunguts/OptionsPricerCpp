#include "StdAfx.h"
#include "PathDependent.h"


PathDependent::PathDependent(const MJArray& LookAtTimes_)
	: LookAtTimes(LookAtTimes_)
{
}

const MJArray& PathDependent::GetLookAtTimes() const
{
	return this->LookAtTimes;
}


	