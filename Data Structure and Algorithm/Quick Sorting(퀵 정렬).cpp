#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // qsort �Լ��� ������ ���

# define MAX_SIZE 10

int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int compare2(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return 1;      // 1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return -1;       // -1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int compare_simple(const void* a, const void* b) //������ ����
{
	return *(int*)a - *(int*)b;    // ��������
}

void Quick_Sorting(int arr[], int start, int end) // �Լ� ���� ����
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

	Quick_Sorting(arr, 0, MAX_SIZE - 1); // ���� ������ �Լ� ���

	// qsort(������ �迭, ��� ����, ��� ũ��, �� �Լ�)
	qsort(arr2, MAX_SIZE, sizeof(int), compare);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr[i]);

	printf("\n");

	for (int j = 0; j < MAX_SIZE; j++)
		printf("%d ", arr2[j]);

	return 0;
}