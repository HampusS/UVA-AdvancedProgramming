// uva11054WineTrading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//Taking out the differens between current number and next number
//and adding it to the awnser
//lastly the next number becomes current itteration number
int n;
int a[1000001];
int main()
{
	while (scanf("%d", &n))
	{
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		long long int ans = 0;
		for (size_t i = 0; i < n - 1; i++)
		{
			ans += abs(a[i]);
			a[i + 1] += a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}