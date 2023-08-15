#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define Array_Size 10

void Bubble_Sorting(int arr[])
{
	int temp = 0;
	for (int i = 0; i < Array_Size; i++)
	{
		for (int j = 0; j < Array_Size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{

	int arr[Array_Size] = { 4, 74, 62, 15, 32, 92, 64, 42, 55, 1 };

	Bubble_Sorting(arr);

	for (int i = 0; i < Array_Size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}