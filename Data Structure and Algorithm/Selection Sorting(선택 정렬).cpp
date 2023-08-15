#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#define swap(a, b, temp) (temp=a, a=b, b=temp)

#include <stdio.h>
#include <stdlib.h>

void Selection_Sorting(int arr[])
{
	int index = 0, temp = 0;
	for (int i = 0; i < SIZE - 1; i++)// ������ ���ڴ� �ڵ����� ���ĵǹǷ� NUM-1 ��ŭ �ݺ�
	{
		int min = INT_MAX;
		for (int j = i; j < SIZE; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		swap(arr[i], arr[index], temp);
	}
}

int main()
{
	int arr[SIZE] = { 1, 1, 4, 6, 11, 10, 3, 1, 2, 13 };
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	Selection_Sorting(arr);

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}