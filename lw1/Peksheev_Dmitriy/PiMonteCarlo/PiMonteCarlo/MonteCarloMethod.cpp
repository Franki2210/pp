#include "stdafx.h"
#include "MonteCarloMethod.h"


MonteCarloMethod::MonteCarloMethod()
{
}


MonteCarloMethod::~MonteCarloMethod()
{
}

double MonteCarloMethod::Calculate(int numberIter, double circleRadius)
{
	int innerCount = 0;

	for (int i = 0; i < numberIter; ++i)
	{
		Point point = RandomizerForPoint::GetRandomPointInSquare(circleRadius);
		if (point.GetX() * point.GetX() + point.GetY() * point.GetY() <= 1) ++innerCount;
	}

	double result = (double)(4. * innerCount / numberIter);

	return result;
}
