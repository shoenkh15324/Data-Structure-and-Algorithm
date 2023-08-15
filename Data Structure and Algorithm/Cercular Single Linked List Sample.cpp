#include <stdio.h>
#include <stdlib.h>

//원형 단일 오름차순 연결리스트 구현

typedef struct _Node1
{
	int data;
	struct _Node1* next;
}NODE;

NODE* head;
void Init()
{
	head = NULL;
}

int InsertNode(int value)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = value;
	newNode->next = NULL;

	if (head == NULL)//empty
	{
		head = newNode;
		head->next = newNode;
		return 1;
	}
	if (newNode->data < head->data)//맨 앞에 추가
	{
		newNode->next = head;
		head->next = newNode;
		return 1;
	}

	newNode->next = head->next;//맨 뒤에 추가(원형 리스트는 순환하는 구조이기 때문에 중간에 추가하는 것은 의미가 없음)
	head->next = newNode;
}

int DeleteNode(int data)
{
	NODE* cur, * prev_cur;
	cur = prev_cur = head;

	if (head == NULL)
	{
		printf("ERROR: list is empty\n");
		return -1;
	}

	if (head->next->data == data)//첫 번째 노드 삭제
	{
		cur = head->next;
		prev_cur = cur->next;
		head->next = prev_cur;
		cur->next = NULL;
		free(cur);
		return 1;
	}

	if (head->data == data)
	{
		while (cur->next != head)
		{
			cur = cur->next;
		}
		head = cur;
		head->next = prev_cur->next;
		prev_cur->next = NULL;
		free(prev_cur);
		return 1;
	}

	for (; cur; cur = cur->next)//중간 노드 삭제
	{
		if (cur->data == data)
		{
			prev_cur->next = cur->next;
			cur->next = NULL;
			free(cur);
			return 1;
		}
		prev_cur = cur;
	}

	printf("ERROR: there is no %d\n", data);
}

void PrintList(int cnt)
{
	NODE* p;
	int a = 0;
	for (p = head; p->next && a < cnt - 1; p = p->next)
	{
		printf("%d->", p->data);
		a++;
	}
	printf("%d\n", p->data);
}

void searchNode(int value)
{
	NODE* cur = head;
	int check = 0;
	while (cur->next != head)
	{
		if (cur->data == value)
		{
			check = 1;
			break;
		}
		cur = cur->next;
	}
	if (check == 1)
		printf("%d is exist\n", value);
	else
		printf("%d isn't exist\n", value);
}

int main()
{
	Init();
	for (int i = 0; i < 5; i++)
	{
		InsertNode(i);
	}
	PrintList(20);
	DeleteNode(0);
	PrintList(10);
	searchNode(1);
	searchNode(0);

	return 0;
}