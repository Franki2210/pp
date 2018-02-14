#include "stdafx.h"
#include "MonteCarloMethod.h"
#include <string>

DWORD WINAPI GeneratePoints(LPVOID numberIters)
{
	double sizeOfSquareSide = CIRCLE_RADIUS * 2.;
	for (; MonteCarloMethod::GetCurrentNumberIter() < (UINT32)numberIters; )
	{
		double x = (double)(rand()) / RAND_MAX * sizeOfSquareSide - CIRCLE_RADIUS;
		double y = (double)(rand()) / RAND_MAX * sizeOfSquareSide - CIRCLE_RADIUS;
		if (x * x + y * y <= 1)
			MonteCarloMethod::IncNumberOfPointsInCircle();

		MonteCarloMethod::IncCurrentNumberIter();
		string progress = to_string(MonteCarloMethod::GetCurrentNumberIter()) + "/" + to_string((UINT32)numberIters) + '\n';
		cout << progress;
	}

	return 0;
}

UINT32 MonteCarloMethod::currentNumberIter = 0;
UINT32 MonteCarloMethod::numberOfPointsInCircle = 0;

void MonteCarloMethod::IncCurrentNumberIter()
{
	InterlockedIncrement(&currentNumberIter);
}

void MonteCarloMethod::IncNumberOfPointsInCircle()
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
	ThreadHandler threadHandler;

	threadHandler.CreateThreads(GeneratePoints, (LPVOID)numberIter, numberThreads);
	threadHandler.Run();

	result = (double)(4. * MonteCarloMethod::GetNumberOfPointsInCircle() / numberIter);
	return result;
}
