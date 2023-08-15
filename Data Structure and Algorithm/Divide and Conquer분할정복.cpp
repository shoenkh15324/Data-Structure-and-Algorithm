#include <stdio.h>

// �� ���� �� ū ���� ��ȯ�ϴ� �Լ�
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ���� ���� �˰������� �迭���� �ִ밪 ã��
int findMax(int arr[], int start, int end) {
    // �迭�� ũ�Ⱑ 1�� ��� �ִ밪�� �ش� ���� ��ü
    if (start == end) {
        return arr[start];
    }

    // �迭�� ������ ������ ���� �߰� �ε��� ���
    int mid = (start + end) / 2;

    // ���� �κ� �迭���� �ִ밪 ã��
    int leftMax = findMax(arr, start, mid);

    // ������ �κ� �迭���� �ִ밪 ã��
    int rightMax = findMax(arr, mid + 1, end);

    // ���� �κ� �迭�� ������ �κ� �迭�� �ִ밪 �� �� �� ū �� ��ȯ
    return max(leftMax, rightMax);
}

int main() {
    int arr[] = { 7, 3, 9, 2, 5, 1, 8, 4, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxValue = findMax(arr, 0, n - 1);
    printf("�迭���� �ִ밪: %d\n", maxValue);

    return 0;
}