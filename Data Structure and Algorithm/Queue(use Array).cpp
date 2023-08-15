#include <stdio.h>
#include <stdlib.h>

//�迭�� �̿��� ���� ť

#define QUEUE_SIZE 5 //ť�� ���� ũ��� 4(���� ť��)

int arr[QUEUE_SIZE];
int head = 0;
int tail = 0;
int Dequeue_value = 0;

int isEmpty()
{
	return (head == tail) ? 1 : 0;
}

int isFull()
{
	return ((tail + 1) % QUEUE_SIZE == head) ? 1 : 0;
}

void Enqueue(int value)
{
	if (!isFull())
	{
		arr[tail] = value;
		tail = ++tail % QUEUE_SIZE;
	}
	else
		printf("ERROR: Queue is full!\n");
}

int Dequeue(int value)
{
	if (!isEmpty())
	{
		for (int i = head; i != tail; i = ++i % QUEUE_SIZE)
		{
			if (value == arr[i])
			{
				Dequeue_value = arr[head];
				head = ++head % QUEUE_SIZE;
				return;
			}
		}
		printf("%d is not exist\n", value);
	}
	else
		printf("Queue is empty\n");
}

void Print_Dequeue_Value()
{
	printf("Dequeue_Value is : %d\n", Dequeue_value);
}

void PrintQueue()
{
	for (int i = head; i != tail; i = ++i % QUEUE_SIZE)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		Enqueue(i);
	}
	PrintQueue();
	Dequeue(7);

	return 0;
}