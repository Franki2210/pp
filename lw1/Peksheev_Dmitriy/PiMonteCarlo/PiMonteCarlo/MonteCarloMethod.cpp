#include "stdafx.h"
#include "MonteCarloMethod.h"
#include <string>

DWORD WINAPI GeneratePoints(LPVOID numberIters)
{
	for (; MonteCarloMethod::GetCurrentNumberIter() < (UINT32)numberIters; )
	{
		string progress = to_string(MonteCarloMethod::GetCurrentNumberIter()) + "/" + to_string((UINT32)numberIters);
		cout << progress << endl;

		pair<double, double> point = RandomizerForPoint::GetRandomCoordinatesInSquare(1.0);
		double x = point.first;
		double y = point.second;
		if (x * x + y * y <= 1)
			MonteCarloMethod::NumberOfPointsInCircleInc();
		MonteCarloMethod::CurrentNumberIterInc();
		if (MonteCarloMethod::GetCurrentNumberIter() > (UINT32)numberIters) break;
	}

	return 0;
}

UINT32 MonteCarloMethod::currentNumberIter = 0;
UINT32 MonteCarloMethod::numberOfPointsInCircle = 0;

MonteCarloMethod::MonteCarloMethod()
{
}


MonteCarloMethod::~MonteCarloMethod()
{
}

void MonteCarloMethod::CurrentNumberIterInc()
{
	InterlockedIncrement(&currentNumberIter);
}

void MonteCarloMethod::NumberOfPointsInCircleInc()
{
	InterlockedIncrement(&numberOfPointsInCircle);
}

unsigned long MonteCarloMethod::GetCurrentNumberIter()
{
	return currentNumberIter;
}

unsigned long MonteCarloMethod::GetNumberOfPointsInCircle()
{
	return numberOfPointsInCircle;
}


double MonteCarloMethod::Calculate(int numberIter, int numberThreads)
{
	ThreadManager threadManager;

	threadManager.CreateThreads(GeneratePoints, (LPVOID)numberIter, numberThreads);
	threadManager.Run();

	result = (double)(4. * MonteCarloMethod::GetNumberOfPointsInCircle() / numberIter);
	return result;
}
