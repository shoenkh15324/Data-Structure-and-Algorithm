#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // qsort 함수가 구현된 헤더

# define MAX_SIZE 10

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int compare2(const void* a, const void* b)    // 내림차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return 1;      // 1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return -1;       // -1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int compare_simple(const void* a, const void* b) //간단한 구현
{
	return *(int*)a - *(int*)b;    // 오름차순
}

void Quick_Sorting(int arr[], int start, int end) // 함수 직접 구현
{
	int left = start, right = end;
	int pivot = arr[(start + end) / 2];
	int temp;
	do
	{
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);

	// recursion //
	if (start < right) Quick_Sorting(arr, start, right);
	if (left < end) Quick_Sorting(arr, left, end);
}

int main()
{
	int arr[MAX_SIZE] = { 5,8,3,4,7,9,6,2,1,10 };
	int arr2[MAX_SIZE] = { 5,8,3,4,7,9,6,2,1,10 };

	Quick_Sorting(arr, 0, MAX_SIZE - 1); // 직접 구현한 함수 사용

	// qsort(정렬할 배열, 요소 개수, 요소 크기, 비교 함수)
	qsort(arr2, MAX_SIZE, sizeof(int), compare);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr[i]);

	printf("\n");

	for (int j = 0; j < MAX_SIZE; j++)
		printf("%d ", arr2[j]);

	return 0;
}