// AdvProg-Assg.2-Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool isEqual;

int CheckEquality() {
	int i_lDistance = 0, i_lWeight = 0,
		i_rDistance = 0, i_rWeight = 0;
	std::cin >> i_lWeight >> i_lDistance >> i_rWeight >> i_rDistance;

	if (i_lWeight == 0)
		i_lWeight = CheckEquality();
	if (i_rWeight == 0)
		i_rWeight = CheckEquality();
	if (i_lDistance * i_lWeight != i_rDistance * i_rWeight)
		isEqual = false;

	return (i_lWeight + i_rWeight);
}

int main()
{
	int i_totalCases = 0;

	std::cin >> i_totalCases;

	while (i_totalCases--) {
		isEqual = true;
		CheckEquality();

		puts(isEqual ? "YES" : "NO");
		if (i_totalCases)
			puts("");

	}

	return 0;
}

