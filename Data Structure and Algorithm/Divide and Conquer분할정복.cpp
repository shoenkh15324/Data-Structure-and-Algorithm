#include <stdio.h>

// 두 정수 중 큰 값을 반환하는 함수
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 분할 정복 알고리즘으로 배열에서 최대값 찾기
int findMax(int arr[], int start, int end) {
    // 배열의 크기가 1인 경우 최대값은 해당 원소 자체
    if (start == end) {
        return arr[start];
    }

    // 배열을 반으로 나누기 위해 중간 인덱스 계산
    int mid = (start + end) / 2;

    // 왼쪽 부분 배열에서 최대값 찾기
    int leftMax = findMax(arr, start, mid);

    // 오른쪽 부분 배열에서 최대값 찾기
    int rightMax = findMax(arr, mid + 1, end);

    // 왼쪽 부분 배열과 오른쪽 부분 배열의 최대값 비교 후 더 큰 값 반환
    return max(leftMax, rightMax);
}

int main() {
    int arr[] = { 7, 3, 9, 2, 5, 1, 8, 4, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxValue = findMax(arr, 0, n - 1);
    printf("배열에서 최대값: %d\n", maxValue);

    return 0;
}