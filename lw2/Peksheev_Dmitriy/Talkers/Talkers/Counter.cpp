#include "stdafx.h"
#include "Counter.h"


static UINT32 number = -1;

Counter::Counter()
{
}


Counter::~Counter()
{
}

int Counter::GetNextNumber()
{
	InterlockedIncrement(&number);
	return number;
}
