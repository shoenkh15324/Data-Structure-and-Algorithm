#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ��� ���Ŀ��� ����� �� �ִ� �ִ� �ڸ���
#define MAX_DIGITS 10
#define Array_Size 8

// ��� ������ ���� �Լ�: ī���� ������ ����Ͽ� �ڸ����� ���� ����
void countingSort(int arr[], int size, int exp) {
    int output[Array_Size];
    int count[10] = { 0 }; // 0���� 9������ ���ڸ� ���� ���� �迭

    // ���� �ڸ����� ���� ���� ����
    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    // ���� �󵵼��� ������Ʈ
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // ���� �迭�� ��ȸ�ϸ� output �迭�� ����
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // output �迭�� ���� �迭�� ����
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

// ��� ���� �Լ�
void radixSort(int arr[], int n) {
    // �ִ밪 ã�� (��� ���Ŀ� ����� �ִ� �ڸ��� ���)
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // �ִ밪�� ���� 1�� �ڸ����� ���� ū �ڸ������� ����
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };

    radixSort(arr, Array_Size);

    for (int i = 0; i < Array_Size; i++) printf("%d ", arr[i]);

    return 0;
}