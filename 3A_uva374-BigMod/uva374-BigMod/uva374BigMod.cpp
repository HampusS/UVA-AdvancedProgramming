// uva374BigMod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
double ModExp(long x, long y, long N);

int z;
long x = 0;
long y = 0;
long N = 0;



int main()
{
	while (cin >> x >> y >> N)
	{
		cout << ModExp(x, y, N) << endl;
	}
	return 0;
}

double ModExp(long x, long y, long N)
{
	if (y == 0) { return 1; }
	z = ModExp(x, (y / 2), N);
	if (y % 2 == 0)
	{
		return (z*z) % N;
	}
	else
	{

		return (x*(z*z)) % N;
	}
}