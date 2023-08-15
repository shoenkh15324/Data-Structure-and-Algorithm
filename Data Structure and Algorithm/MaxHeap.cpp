#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
	int data;
}element;

typedef struct heap
{
	element heap[MAX_SIZE];
	int size;
}HEAP;

void InitHeap(HEAP* h)
{
	h->size = 0;
}

void Insert(HEAP* h, element value)
{
	int i;
	i = ++(h->size);

	while ((i != 1) && (value.data > h->heap[i / 2].data))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = value;
}

element Delete(HEAP* h)
{
	if (h->size == 0) return;

	element temp = h->heap[1];
	h->heap[1] = h->heap[h->size--];
	int parent = 1, child;

	while (1)
	{
		child = parent * 2;
		if ((child + 1 <= h->size) && (h->heap[child].data < h->heap[child + 1].data))
			child++;

		if (h->heap[child].data <= h->heap[parent].data || child > h->size)
			break;

		element tmp = h->heap[parent];
		h->heap[parent] = h->heap[child];
		h->heap[child] = tmp;
		parent = child;
	}
	return temp;
}


int main()
{
	HEAP h;
	element item;
	InitHeap(&h);
	item.data = 9;
	Insert(&h, item);
	item.data = 7;
	Insert(&h, item);
	item.data = 6;
	Insert(&h, item);
	item.data = 4;
	Insert(&h, item);
	item.data = 5;
	Insert(&h, item);
	item.data = 1;
	Insert(&h, item);
	item.data = 3;
	Insert(&h, item);
	item.data = 8;
	Insert(&h, item);

	while (h.size > 0)
	{
		item = Delete(&h);
		printf("%d ", item.data);
	}

	return 0;
}