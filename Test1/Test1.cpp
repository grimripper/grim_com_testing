// Test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>

void printArrOut(int* x)
{
	uint16_t* my_arr = reinterpret_cast<uint16_t*>(x);
}


int _tmain(int argc, _TCHAR* argv[])
{

	int x[] = { 0, 1, 2, 3, 4 };
	printArrOut(x);

	return 0;
}


