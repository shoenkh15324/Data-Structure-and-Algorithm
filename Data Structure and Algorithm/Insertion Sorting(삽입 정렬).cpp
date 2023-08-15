#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

# define MAX_SIZE 5

// 오름차순 기준

void Insertion_Sorting(int arr[], int n)
{
	int i = 0, j = 0, key = 0;
	for (i = 0; i < n; i++)
	{
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}

int main()
{
	int arr[MAX_SIZE] = { 8, 5, 6, 2, 4 };

	Insertion_Sorting(arr, MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr[i]);
}