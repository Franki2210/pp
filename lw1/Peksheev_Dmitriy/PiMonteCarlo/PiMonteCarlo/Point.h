#pragma once

class Point
{
public:
	Point();
	~Point();

	Point(double x, double y);
	void Set(double x, double y);

	double GetX();
	double GetY();
private:
	double x;
	double y;
};
