#pragma once
#include "stdafx.h"

using namespace std;

class Talker
{
public:
	Talker(int id);
	~Talker();

	void CallOtherTalker(vector<Talker> & talkers);

	Talker *GetRandomTalker(vector<Talker> & talkers);

	int GetRandomTime();

	bool Answer();
	void EndTalk();

	int GetId();
private:
	int m_id;
	HANDLE mutex;

	const int MIN_TIME = 1000;
	const int MAX_TIME = 4000;
};

