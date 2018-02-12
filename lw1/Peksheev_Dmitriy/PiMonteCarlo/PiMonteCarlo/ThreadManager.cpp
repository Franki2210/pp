#include "stdafx.h"
#include "ThreadManager.h"

void ThreadManager::CreateThreads(LPTHREAD_START_ROUTINE threadProc, LPVOID param, int numberThreads)
{
	SetThreadProc(threadProc);
	SetParam(param);
	SetNumberThreads(numberThreads);
	for (int i = 0; i < numberThreads; ++i)
	{
		m_handles.push_back(CreateThread(NULL, 0, threadProc, param, CREATE_SUSPENDED, NULL));
	}
}

void ThreadManager::Run()
{
	for (int i = 0; i < numberThreads; ++i)
		ResumeThread(m_handles.at(i));

	WaitForMultipleObjects(numberThreads, m_handles.data(), true, INFINITE);
}

void ThreadManager::SetNumberThreads(int numberThreads)
{
	this->numberThreads = numberThreads;
}

void ThreadManager::SetThreadProc(LPTHREAD_START_ROUTINE threadProc)
{
	this->threadProc = threadProc;
}

void ThreadManager::SetParam(LPVOID param)
{
	this->param = param;
}
