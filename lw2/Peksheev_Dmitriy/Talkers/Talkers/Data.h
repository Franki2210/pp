#pragma once
#include "Talker.h"

struct Data
{
	Data(int id, vector<Talker> talkers)
		: id(id),
		talkers(talkers)
	{

	}
	int id;
	std::vector<Talker> talkers;
};
