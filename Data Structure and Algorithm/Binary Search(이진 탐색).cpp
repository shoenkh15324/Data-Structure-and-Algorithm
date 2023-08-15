#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // bsearch 함수가 구현된 헤더

#define MAX_SIZE 7

// 이진탐색은 데이터가 반드시 정렬되있어야 한다.

// 반복문을 이용한 구현
int binarySearch(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key) return mid; // 검색 성공
		else if (arr[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return -1; // 검색 실패
}

// 재귀함수를 이용한 구현
int binarySearch2(int arr[], int low, int high, int key)
{
	if (low > high) return -1; // 검색 실패

	int mid = low + (high - low) / 2;

	if (arr[mid] == key) return mid; // 검색 성공
	else if (arr[mid] > key) return binarySearch2(arr, low, high, key);
	else return binarySearch2(arr, low, high, key);
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	//예제
	//다음 배열에서 이진탐색을 이용하여 43을 찾아라.
	int arr[MAX_SIZE] = { 17, 28, 43, 67, 88, 92, 100 };

	int ans = binarySearch(arr, 0, 6, 43);

	int key = 43;

	// bsearch(찾을 값의 주소, 배열이름, 배열 크기, 요소 크기, 비교 함수 포인터)
	int* ans2 = (int*)bsearch(&key, arr, MAX_SIZE, sizeof(int), compare); // besearch함수의 기본 반환타입은 void형

	printf("%d\n", ans);
	printf("%d\n", *ans2);

	return 0;
}