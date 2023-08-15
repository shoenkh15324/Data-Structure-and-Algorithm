#define _CRT_SECURE_NO_WARNINGS

//배열이나 리스트와 같은 데이터 구조에서 특정 값을 찾기 위해 순서대로 원소를 검사하는 방법
//선형탐색(Linear Search)라고도 한다.

#define ARRAY_SIZE 7

#include <stdio.h>

int Sequential_Search(int arr[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target) return i;
	}
	return -1;
}

int main()
{
	int arr[ARRAY_SIZE] = { 1, 5, 9, 3, 7, 12, 8 };
	int target = 7;

	int result = Sequential_Search(arr, ARRAY_SIZE, target);
	if (result == -1) printf("ERROR\n");
	else printf("원소 % d는 인덱스 % d에서 찾았습니다.\n", target, result);

	return 0;
}