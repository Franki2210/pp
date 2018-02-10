#pragma once
#include "stdafx.h"
#include <Windows.h>
#include <vector>

using namespace std;

class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();
private:
	vector<HANDLE> m_handles;
};

