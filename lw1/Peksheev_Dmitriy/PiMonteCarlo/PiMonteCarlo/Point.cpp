#include "stdafx.h"
#include "Point.h"

Point::Point() {}

Point::~Point()
{
}

Point::Point(double x, double y)
{
	Set(x, y);
}

void Point::Set(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point::GetX()
{
	return x;
}

double Point::GetY()
{
	return y;
}
