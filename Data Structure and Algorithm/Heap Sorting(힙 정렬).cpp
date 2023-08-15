#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//��: �θ��� ���� �ڽ��� ������ �׻� ũ�ٴ� ������ �����ϴ� ��������Ʈ��

#define Array_Size 10

void Heap_Sorting(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int c = i;//�ڽ� ���
		do
		{
			int parent = (c - 1) / 2; // �ڽĳ�忡�� 1�� ���� 2�� ������ �θ� ��尡 ����
			if (arr[parent] < arr[c])//���� �θ� ��庸�� �ڽ� ��尡 ũ�ٸ� ���� �ٲ۴�.
			{
				int temp = arr[parent];
				arr[parent] = arr[c];
				arr[c] = temp;
			}
			c = parent;//������ ������ �� ���� �� �ö󰡼� ��Ʈ���� ���鼭 �˻�
		} while (c != 0);
	}

	//���� �������� ���Ͽ� ���� ū ���� ��Ʈ�� �Ǿ����Ƿ�
	//��Ʈ�� �ݺ������� ���� ������ �����ٸ� �ڿ������� ������������ ������ ��.
	//ũ�⸦ �ٿ����� �ݺ������� ���� ����

	for (int i = size - 1; i >= 0; i--)
	{
		//���� ū ���� �� �ڷ� ����
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		//�� ���� �����
		int parent = 0, c = 1;
		do
		{
			c = parent * 2 + 1;
			//�ڽ� �߿� �� ū ���� ã�� && ������ ����� �ʰ� ������
			if (arr[c] < arr[c + 1] && c < i - 1) c++; // ���� �ڽİ� ������ �ڽ� �߿� �� ū ���� ���� �ڽ��� c�� ����
			if (arr[parent] < arr[c] && c < i) // �θ𺸴� �ڽ��� �� ũ�� ��ȯ
			{
				temp = arr[parent];
				arr[parent] = arr[c];
				arr[c] = temp;
			}
			parent = c; // �� ������ �������� ���� �θ� ���� �ڽ����� �־���
		} while (c < i); // ���ĵ� ������ ���� �ʵ��� ��
	}
}



int main()
{
	int arr[Array_Size] = { 5, 6, 10, 4, 3, 8, 7, 1, 2, 9 };

	Heap_Sorting(arr, Array_Size);

	for (int i = 0; i < Array_Size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}