#include "StdAfx.h"
#include "StatisticsMC.h"

StatisticsMean::StatisticsMean() : RunningSum(0.0), PathsDone(0ul)
{

}

void StatisticsMean::DumpOneResult(double result)
{
	PathsDone++;
	RunningSum += result;
}

std::vector<std::vector<double>> StatisticsMean::GetResultsSoFar() const
{
	std::vector<std::vector<double>> Results(1);

	Results[0].resize(1);
	Results[0][0] = RunningSum/PathsDone;

	return Results;
}

StatisticsMC* StatisticsMean::clone() const
{
	return new StatisticsMean(*this);
}