// AdvProg-Assg.1-Task3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	std::string s_temp, s_result;
	std::getline(std::cin, s_temp);

	while (s_temp[0] != '|')
		std::getline(std::cin, s_temp);

	while (s_temp[0] == '|')
	{
		int pos(7);
		int value(0);

		for (std::string::const_iterator c = s_temp.begin() + 1; pos >= 0; ++c)
		{
			if (c == s_temp.end())
				break;
			if (*c == ' ' || *c == 'o')
			{
				if (*c == 'o')
					value += (1 << pos);
				--pos;
			}
		}
		s_result += static_cast<char>(value);
		std::getline(std::cin, s_temp);
	}
	std::cout << s_result;
}

