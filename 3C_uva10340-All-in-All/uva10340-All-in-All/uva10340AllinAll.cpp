// uva10340AllinAll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

bool sub(string a, string b) {
	int index = 0;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == a[index])
			index++;
		if (index == a.length()) return true;
	}
	return false;
}

int main() {
	string a, b;

	while (cin >> a >> b) {
		if (a.length() > b.length())
			cout << "No\n";
		else {
			if (sub(a, b))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}

	return 0;
}