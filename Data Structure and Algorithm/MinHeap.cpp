#include <stdio.h>

#define MAX_SIZE 100

typedef struct datatype
{
	int data;
}element;

typedef struct Heap
{
	element heap[MAX_SIZE];
	int size;
}HEAP;

HEAP h;
element item;

void Insert(element value)
{
	int i = ++h.size;
	h.heap[i] = value;

	while ((i != 1) && (value.data < h.heap[i / 2].data))
	{
		h.heap[i] = h.heap[i / 2];
		i /= 2;
	}
	h.heap[i] = value;
}

void Delete()
{
	int temp = h.heap[1].data;
	h.heap[1] = h.heap[h.size--];
	int parent = 1, child;

	while (1)
	{
		child = 2 * parent;
		if (child + 1 < h.size && (h.heap[child].data > h.heap[child + 1].data))
			child++;

		if (child > h.size || h.heap[child].data >= h.heap[parent].data)
			break;

		int tmp = h.heap[parent].data;
		h.heap[parent] = h.heap[child];
		h.heap[child].data = tmp;

		parent = child;
	}
}

void Print()
{
	for (int i = 1; i <= h.size; i++)
		printf("%d ", h.heap[i].data);
	printf("\n");
}

int main()
{
	item.data = 9;
	Insert(item);
	item.data = 2;
	Insert(item);
	item.data = 4;
	Insert(item);
	item.data = 5;
	Insert(item);
	item.data = 1;
	Insert(item);
	item.data = 3;
	Insert(item);
	item.data = 8;
	Insert(item);
	item.data = 1;
	Insert(item);
	Print();
	Delete();
	Print();


	return 0;
}