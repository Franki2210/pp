#include "stdafx.h"
#include "RandomizerForPoint.h"

Point RandomizerForPoint::GetRandomPointInSquare(double circleRadius)
{
	Point point;

	double sizeOfSquareSide = circleRadius * 2.0;

	double x = (double)(rand()) / RAND_MAX * sizeOfSquareSide - circleRadius;
	double y = (double)(rand()) / RAND_MAX * sizeOfSquareSide - circleRadius;
	point.Set(x, y);
	return point;
}
