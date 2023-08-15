#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//힙: 부모의 값이 자식의 값보다 항상 크다는 조건을 만족하는 완전이진트리

#define Array_Size 10

void Heap_Sorting(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int c = i;//자식 노드
		do
		{
			int parent = (c - 1) / 2; // 자식노드에서 1을 빼고 2를 나누면 부모 노드가 나옴
			if (arr[parent] < arr[c])//만약 부모 노드보다 자식 노드가 크다면 값을 바꾼다.
			{
				int temp = arr[parent];
				arr[parent] = arr[c];
				arr[c] = temp;
			}
			c = parent;//과정이 끝나고 한 레벨 더 올라가서 루트까지 가면서 검사
		} while (c != 0);
	}

	//위의 과정으로 인하여 가장 큰 값이 루트가 되었으므로
	//루트를 반복적으로 가장 밑으로 내린다면 자연스럽게 오름차순으로 정렬이 됨.
	//크기를 줄여가며 반복적으로 힙을 구성

	for (int i = size - 1; i >= 0; i--)
	{
		//가장 큰 값을 맨 뒤로 보냄
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		//힙 구조 만들기
		int parent = 0, c = 1;
		do
		{
			c = parent * 2 + 1;
			//자식 중에 더 큰 값을 찾기 && 범위를 벗어나지 않게 막아줌
			if (arr[c] < arr[c + 1] && c < i - 1) c++; // 왼쪽 자식과 오른쪽 자식 중에 더 큰 값을 가진 자식을 c에 저장
			if (arr[parent] < arr[c] && c < i) // 부모보다 자식이 더 크면 교환
			{
				temp = arr[parent];
				arr[parent] = arr[c];
				arr[c] = temp;
			}
			parent = c; // 한 레벨씩 내려가기 위해 부모를 현재 자식으로 넣어줌
		} while (c < i); // 정렬된 곳까지 가지 않도록 함
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