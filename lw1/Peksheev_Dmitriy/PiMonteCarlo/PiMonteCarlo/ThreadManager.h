#pragma once
#include "stdafx.h"
#include <Windows.h>
#include <vector>

#include "MonteCarloMethod.h"

using namespace std;

class ThreadManager
{
public:
	void CreateThreads(LPTHREAD_START_ROUTINE threadProc, LPVOID param, int numberThreads);
	void Run();

	void SetNumberThreads(int numberThreads);
	void SetThreadProc(LPTHREAD_START_ROUTINE threadProc);
	void SetParam(LPVOID param);
private:
	int numberThreads;
	vector<HANDLE> m_handles;
	LPTHREAD_START_ROUTINE threadProc;
	LPVOID param;
};

