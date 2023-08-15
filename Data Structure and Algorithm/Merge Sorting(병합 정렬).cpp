#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

# define MAX_SIZE 8

int sorted[MAX_SIZE]; //���ҵ� �迭�� �����ϴ� �ӽ����� �迭

void Merge(int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left, l;

	// ���� ���ĵ� �迭 �պ� //
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	// �����ִ� ������ �ϰ� ���� // 
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}

	// sorted�� �迭�� arr�� �纹�� // 
	for (l = left; l <= right; l++)
	{
		arr[l] = sorted[l];
	}
}

void Merge_Sorting(int arr[], int left, int right) // ���� ����
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� �迭�� �յ��ϰ� ����-����(Divide)
		Merge_Sorting(arr, left, mid); // ���� �κ� ���� - ����(Conquer)
		Merge_Sorting(arr, mid + 1, right); // ���� �κ� ���� - ����(Conquer)
		Merge(arr, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ� - ����(Combine)
	}
}

int main()
{
	int arr[MAX_SIZE] = { 21, 10, 12, 20, 25, 13, 15, 22 };

	Merge_Sorting(arr, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr[i]);

	return 0;
}