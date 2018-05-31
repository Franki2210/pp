#include "stdafx.h"
#include "Timer.h"

Timer::Timer()
{
	startTime = 0;
	endTime = 0;
}

void Timer::Start()
{
	startTime = clock();
	isWork = true;
}

void Timer::Stop()
{
	endTime = clock();
	isWork = false;
}

double Timer::GetDuration()
{
	return (endTime - startTime) / (double)CLOCKS_PER_SEC;
}

double Timer::GetCurrDuration()
{
	return (clock() - startTime) / (double)CLOCKS_PER_SEC;
}

bool Timer::IsWork()
{
	return isWork;
}
