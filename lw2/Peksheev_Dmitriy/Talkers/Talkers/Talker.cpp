#include "stdafx.h"
#include <random>
#include "Talker.h"
#include "Counter.h"

using namespace std;

Talker::Talker(int id)
{
	m_id = id;
	mutex = CreateMutex(NULL, 0, NULL);
}

Talker::~Talker()
{
}

void Talker::CallOtherTalker(vector<Talker> & talkers)
{
	Sleep(GetRandomTime());
	WaitForSingleObject(mutex, INFINITE);

	Talker *otherTalker = GetRandomTalker(talkers);
	printf("Talker#%d call to talker#%d\n", m_id, otherTalker->GetId());

	if (otherTalker->Answer())
	{
		printf("Talker#%d talks with talker#%d\n", m_id, otherTalker->GetId());
		Sleep(GetRandomTime());

		printf("Talker#%d end talk with talker#%d\n", m_id, otherTalker->GetId());
		otherTalker->EndTalk();
	}
	else
	{
		printf("Talker#%d is busy\n", otherTalker->GetId());
	}
	ReleaseMutex(mutex);
}

Talker *Talker::GetRandomTalker(vector<Talker> & talkers)
{
	mt19937 generator { random_device()() };
	uniform_int_distribution<int> rand(0, talkers.size() - 1);

	int numberTalker;
	Talker * otherTalker;
	do
	{
		numberTalker = rand(generator);
		otherTalker = &talkers[numberTalker];
	} while (otherTalker == this);	

	return otherTalker;
}

int Talker::GetRandomTime()
{
	mt19937 generator{ random_device()() };
	uniform_int_distribution<int> rand(MIN_TIME, MAX_TIME);
	int time = rand(generator);
	return time;
}

bool Talker::Answer()
{
	DWORD status = WaitForSingleObject(mutex, 0);
	return status == WAIT_OBJECT_0;
}

void Talker::EndTalk()
{
	ReleaseMutex(mutex);

}

int Talker::GetId()
{
	return m_id;
}