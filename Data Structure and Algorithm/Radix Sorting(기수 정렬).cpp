#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 기수 정렬에서 사용할 수 있는 최대 자릿수
#define MAX_DIGITS 10
#define Array_Size 8

// 기수 정렬의 보조 함수: 카운팅 정렬을 사용하여 자릿수에 따라 정렬
void countingSort(int arr[], int size, int exp) {
    int output[Array_Size];
    int count[10] = { 0 }; // 0부터 9까지의 숫자를 세기 위한 배열

    // 현재 자릿수에 따라 숫자 세기
    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    // 누적 빈도수로 업데이트
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 원래 배열을 순회하며 output 배열에 정렬
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // output 배열을 원래 배열에 복사
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

// 기수 정렬 함수
void radixSort(int arr[], int n) {
    // 최대값 찾기 (기수 정렬에 사용할 최대 자릿수 계산)
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // 최대값에 따라 1의 자리부터 가장 큰 자릿수까지 정렬
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };

    radixSort(arr, Array_Size);

    for (int i = 0; i < Array_Size; i++) printf("%d ", arr[i]);

    return 0;
}