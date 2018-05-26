#include "stdafx.h"
#include <chrono>
#include <thread>
#include "MonteCarloMethod.h"
#include "Logger.h"

using namespace std;

DWORD WINAPI PrintProgress(LPVOID param)
{
	UINT32 numberIters = (UINT32)param;
	string progress;
	while (MonteCarloMethod::GetCurrentNumberIter() <= numberIters)
	{
		progress = to_string(MonteCarloMethod::GetCurrentNumberIter()) + "/" + to_string(numberIters) + "\r";
		cout << progress;
		std::this_thread::sleep_for(chrono::milliseconds(100));
	}
	return 0;
}