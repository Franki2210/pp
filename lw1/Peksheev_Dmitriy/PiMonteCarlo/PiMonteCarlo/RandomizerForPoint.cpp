#include "stdafx.h"
#include "RandomizerForPoint.h"

pair<double, double> RandomizerForPoint::GetRandomCoordinatesInSquare(double circleRadius)
{
	double sizeOfSquareSide = circleRadius * 2.0;

	double x = (double)(rand()) / RAND_MAX * sizeOfSquareSide - circleRadius;
	double y = (double)(rand()) / RAND_MAX * sizeOfSquareSide - circleRadius;
	return make_pair(x, y);
}
