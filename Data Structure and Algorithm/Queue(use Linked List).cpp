#include <stdio.h>
#include <stdlib.h>

//이중 연결리스트를 이용한 큐

typedef struct _Node
{
	int data;
	struct _Node* next;
	struct _Node* prev;
}NODE;

NODE* head;
NODE* tail;

void Init()
{
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	head->data = 0;
	tail->data = 0;
	head->next = NULL;
	head->prev = head;
	tail->next = NULL;
	tail->prev = head;
}

void Enqueue(int value)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = value;
	NODE* ptr = tail;
	newNode->next = ptr;
	ptr->prev->next = newNode;
	newNode->prev = tail->prev;
	tail->prev = newNode;
}

void Dequeue()
{
	if (head->next == NULL)
	{
		printf("ERROR: Queue is empty!\n");
		return;
	}
	NODE* ptr = head->next;
	head->next = ptr->next;
	ptr->next->prev = head;
	ptr->next = NULL;
	ptr->prev = NULL;
	free(ptr);
}

void PrintQueue()
{
	NODE* ptr = head->next;
	if (ptr->next == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		while (ptr->next != tail)
		{
			printf("%d->", ptr->data);
			ptr = ptr->next;
		}
		printf("%d\n", ptr->data);
	}
}

int main() {
	Init();
	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	PrintQueue();
	Dequeue();
	PrintQueue();
	Dequeue();
	PrintQueue();
	Dequeue();
	PrintQueue();
	Dequeue();
	PrintQueue();

	return 0;
}