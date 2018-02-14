#include "stdafx.h"
#include "MonteCarloMethod.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Please input <program> <number iterations> <number threads>" << endl;
		return EXIT_FAILURE;
	}

	size_t numberIter = atoi(argv[1]);
	size_t numberThreads = atoi(argv[2]);

	clock_t start = clock();
	MonteCarloMethod monteCarloMethod;
	double result = monteCarloMethod.Calculate(numberIter, numberThreads);

	cout.precision(10);
	cout << "Result: " << result << endl;

	double operatingTime = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << "Time: " << operatingTime << " sec" << endl;

    return 0;
}


