#include "stdafx.h"

#include "Talker.h"
#include "Counter.h"
#include "ThreadHandler.h"

using namespace std;

const int ARG_COUNT = 2;

DWORD WINAPI Process(LPVOID lpParam)
{
	vector<Talker> talkers = *(vector<Talker>*)lpParam;

	Talker *talker = &talkers.at(Counter::GetNextNumber());

	while (true)
	{
		talker->CallOtherTalker(talkers);
	}

	return 0;
}

int main(int argc, char* argv[])
{
	size_t numberOfTalkers = atoi(argv[1]);

	if (argc != ARG_COUNT)
	{
		cout << ">Invalid count of arguments!\n"
			<< "Use: Talkers.exe <talkers count>\n";
		return EXIT_FAILURE;
	}

	vector<Talker> talkers;

	for (int i = 0; i < numberOfTalkers; ++i)
	{
		talkers.push_back(Talker(i + 1));
	}

	ThreadHandler threadHandler;
	threadHandler.CreateThreads(Process, &talkers, numberOfTalkers);
	threadHandler.Run();

    return 0;
}


