// AdvProg-Assg.1-Task1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

int main()
{
	int nrTests,
		nrFarmers,
	    farmSizeSqrd,
		nrAnimals,
		friendliness;

	std::cin >> nrTests;

	for (int i = 0; i < nrTests; ++i)
	{
		std::cin >> nrFarmers;
		int premium = 0;
		for (int i = 0; i < nrFarmers; i++)
		{
			std::cin >> farmSizeSqrd >> nrAnimals >> friendliness;
			int animalPremium = farmSizeSqrd * friendliness;

			premium += animalPremium;
		}

		std::cout << premium << "\n";
	}
	return 0;
}


