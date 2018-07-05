// AdvProg-Assg.1-Task2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
void QuickSort(int arr[], int left, int right);
void BalanceArray(int arr[], int median, int size, int& moves);

int main()
{
	int i_count = 0,
		i_sets = 0,
		i_moves,
		i_sum;

	while (std::cin >> i_count) {
		if (i_count == 0)
			break;
		int* i_array = new int[i_count];
		++i_sets;

		i_sum = 0;
		i_moves = 0;

		for (int i = 0; i < i_count; i++)
		{
			std::cin >> i_array[i];
			i_sum += i_array[i];
		}

		QuickSort(i_array, 0, i_count - 1);
		BalanceArray(i_array, (i_sum / i_count), i_count, i_moves);

		for (int i = 0; i < i_count; i++)
		{
			printf("%ld", i_array[i]);
		}

		printf("\nSet #%ld\n", i_sets);
		printf("The minimum number of moves is %ld.\n\n", i_moves);
	}

	return 0;
}

void BalanceArray(int arr[], int median, int size, int& moves) {
	int lower = 0,
		upper = size - 1;
	while (lower != upper) {
		if (arr[lower] < median) {
			if (arr[upper] > median) {
				++arr[lower];
				--arr[upper];
				++moves;
			}
			else --upper;
		}
		else ++lower;
	}
}

void Swap(int arr[], int left, int right) {
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[right],
		index = left;
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot)
		{
			Swap(arr, i, index);
			++index;
		}
	}
	Swap(arr, index, right);
	return index;
}

void QuickSort(int arr[], int left, int right) {
	if (left < right) {
		int index = Partition(arr, left, right);
		QuickSort(arr, left, index - 1);
		QuickSort(arr, index + 1, right);
	}
}

