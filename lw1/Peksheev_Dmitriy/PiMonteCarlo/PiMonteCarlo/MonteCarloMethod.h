#pragma once
#include "Point.h"
#include "RandomizerForPoint.h"

class MonteCarloMethod
{
public:
	MonteCarloMethod();
	~MonteCarloMethod();

	double Calculate(int numberIter, double circleRadius);
};

