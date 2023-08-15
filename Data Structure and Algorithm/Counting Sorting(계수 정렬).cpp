#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define Array_Size 13
#define Max 30

void Counting_Sorting(int arr[], int size)
{
	int count[Max] = { 0 };

	for (int i = 0; i < Array_Size; i++)
	{
		int val = arr[i];
		count[val]++;//개수 세기
	}

	for (int i = 0; i < Max; i++)
	{
		for (int j = 0; j < count[i]; j++) printf("%d ", i);
	}
}

int main()
{
	int arr[Array_Size] = { 1,3,2,4,1,23,12,12,3,12,3,23,23 };

	Counting_Sorting(arr, Array_Size);

	return 0;
}