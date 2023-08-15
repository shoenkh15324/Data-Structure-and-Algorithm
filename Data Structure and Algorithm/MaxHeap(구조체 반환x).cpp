#include <stdio.h>

#define MAX_SIZE 100

typedef struct heap
{
	int heap[MAX_SIZE];
	int size;
}HEAP;

HEAP h;

void Init()
{
	h.size = 0;
}

void Insert(int value)
{
	int i = ++h.size;
	h.heap[i] = value;

	while ((i != 1) && (value > h.heap[i / 2]))
	{
		h.heap[i] = h.heap[i / 2];
		i /= 2;
	}
	h.heap[i] = value;
}

void Delete()
{
	h.heap[1] = h.heap[h.size--];
	int parent = 1, child;

	while (1)
	{
		child = 2 * parent;

		if ((child + 1 < h.size) && (h.heap[child] < h.heap[child + 1]))
			child++;

		if (child > h.size || h.heap[child] <= h.heap[parent])
			break;

		int swap = h.heap[parent];
		h.heap[parent] = h.heap[child];
		h.heap[child] = swap;

		parent = child;
	}
}

void Print()
{
	for (int i = 1; i <= h.size; i++)
		printf("%d ", h.heap[i]);
	printf("\n");
}

int main()
{
	Init();
	Insert(9);
	Insert(7);
	Insert(6);
	Insert(4);
	Insert(5);
	Insert(1);
	Insert(3);
	Insert(8);
	Print();
	Delete();
	Print();
	Delete();
	Print();
	Delete();
	Print();
	Delete();
	Print();

	return 0;
}