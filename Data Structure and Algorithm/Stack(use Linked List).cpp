#include <stdio.h>
#include <stdlib.h>

//이중 연결형 리스트를 이용한 스택

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

void AddStack(int value)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = value;
	NODE* ptr = tail;
	newNode->next = ptr;
	ptr->prev->next = newNode;
	newNode->prev = tail->prev;
	tail->prev = newNode;
}

void RemoveStack()
{
	NODE* ptr = tail->prev;
	tail->prev = ptr->prev;
	ptr->prev->next = tail;
	ptr->prev = NULL;
	ptr->next = NULL;
	free(ptr);
}

void PrintStack()
{
	NODE* ptr = head->next;
	while (ptr->next != tail)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
}

int main() {
	Init();
	AddStack(1);
	AddStack(2);
	AddStack(3);
	AddStack(5);
	AddStack(100);
	PrintStack();
	RemoveStack();
	PrintStack();

	return 0;
}