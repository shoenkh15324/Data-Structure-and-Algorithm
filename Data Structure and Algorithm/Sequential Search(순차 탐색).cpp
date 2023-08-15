#define _CRT_SECURE_NO_WARNINGS

//�迭�̳� ����Ʈ�� ���� ������ �������� Ư�� ���� ã�� ���� ������� ���Ҹ� �˻��ϴ� ���
//����Ž��(Linear Search)��� �Ѵ�.

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
	else printf("���� % d�� �ε��� % d���� ã�ҽ��ϴ�.\n", target, result);

	return 0;
}