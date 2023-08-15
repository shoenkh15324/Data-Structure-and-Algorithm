#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // bsearch �Լ��� ������ ���

#define MAX_SIZE 7

// ����Ž���� �����Ͱ� �ݵ�� ���ĵ��־�� �Ѵ�.

// �ݺ����� �̿��� ����
int binarySearch(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key) return mid; // �˻� ����
		else if (arr[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return -1; // �˻� ����
}

// ����Լ��� �̿��� ����
int binarySearch2(int arr[], int low, int high, int key)
{
	if (low > high) return -1; // �˻� ����

	int mid = low + (high - low) / 2;

	if (arr[mid] == key) return mid; // �˻� ����
	else if (arr[mid] > key) return binarySearch2(arr, low, high, key);
	else return binarySearch2(arr, low, high, key);
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	//����
	//���� �迭���� ����Ž���� �̿��Ͽ� 43�� ã�ƶ�.
	int arr[MAX_SIZE] = { 17, 28, 43, 67, 88, 92, 100 };

	int ans = binarySearch(arr, 0, 6, 43);

	int key = 43;

	// bsearch(ã�� ���� �ּ�, �迭�̸�, �迭 ũ��, ��� ũ��, �� �Լ� ������)
	int* ans2 = (int*)bsearch(&key, arr, MAX_SIZE, sizeof(int), compare); // besearch�Լ��� �⺻ ��ȯŸ���� void��

	printf("%d\n", ans);
	printf("%d\n", *ans2);

	return 0;
}