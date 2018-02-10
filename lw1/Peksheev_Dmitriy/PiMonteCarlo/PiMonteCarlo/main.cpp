// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "RandomizerForPoint.h"
#include "Point.h"
#include <windows.h>
#include "MonteCarloMethod.h"

using namespace std;

const int CIRCLE_RADIUS = 1;

//в аргументах передаётся кол-во итераций и потоков
//в конце выводим результат и время
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Please input <program> <number iterations> <number threads>" << endl;
		return EXIT_FAILURE;
	}

	int numberIter = atoi(argv[1]);
	int numberThreads = atoi(argv[2]);

	MonteCarloMethod monteCarloMethod;
	
	double result = monteCarloMethod.Calculate(numberIter, CIRCLE_RADIUS);

	cout.precision(10);
	cout << result << endl;

    return 0;
}


