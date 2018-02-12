#pragma once
#include "RandomizerForPoint.h"
#include <Windows.h>
#include "ThreadManager.h"

DWORD WINAPI GeneratePoints(LPVOID numberIter);

class MonteCarloMethod
{
public:
	MonteCarloMethod();
	~MonteCarloMethod();

	double Calculate(int numberIter, int numberThreads);

	static void CurrentNumberIterInc();
	static void NumberOfPointsInCircleInc();
	static unsigned long GetCurrentNumberIter();
	static unsigned long GetNumberOfPointsInCircle();

private:
	static UINT32 currentNumberIter;
	static UINT32 numberOfPointsInCircle;
	double result;
};

