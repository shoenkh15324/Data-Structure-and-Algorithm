#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

# define MAX_SIZE 8

int sorted[MAX_SIZE]; //분할된 배열을 보관하는 임시적인 배열

void Merge(int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left, l;

	// 분할 정렬된 배열 합병 //
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	// 남아있는 값들을 일괄 복사 // 
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

	// sorted의 배열을 arr로 재복사 // 
	for (l = left; l <= right; l++)
	{
		arr[l] = sorted[l];
	}
}

void Merge_Sorting(int arr[], int left, int right) // 병합 정렬
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; // 중간 위치를 계산하여 배열을 균등하게 분할-분할(Divide)
		Merge_Sorting(arr, left, mid); // 앞쪽 부분 정렬 - 정복(Conquer)
		Merge_Sorting(arr, mid + 1, right); // 뒤쪽 부분 정렬 - 정복(Conquer)
		Merge(arr, left, mid, right); // 정렬된 2개의 부분 배열을 합병 - 결합(Combine)
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