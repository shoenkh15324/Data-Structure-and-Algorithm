#include <stdio.h>
#include <stdlib.h>

//정수형 데이터를 오름차순으로 정렬하는 단일 연결리스트

typedef struct _Node
{
	int data;
	struct _Node* next;
}NODE;

NODE* head;
void init()
{
	head = NULL;
}

void Insert(int data)
{
	NODE* ptr;
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;

	//리스트가 비어있을때
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		if (head->data > newNode->data)//맨 앞에 추가
		{
			newNode->next = head;
			head = newNode;
			return;
		}

		for (ptr = head; ptr->next; ptr = ptr->next)//중간에 추가
		{
			if (ptr->data <newNode->data && ptr->next->data > newNode->data)
			{
				newNode->next = ptr->next;
				ptr->next = newNode;
				return;
			}
		}

		ptr->next = newNode;//맨 끝에 추가
	}
}

int Delete_Node(int data)
{
	NODE* cur;
	NODE* prev_cur;
	cur = prev_cur = head;

	if (head == NULL)
	{
		printf("ERROR: List is empty\n");
		return -1;
	}

	if (head->data == data)//맨 처음 데이터 삭제
	{
		head = cur->next;
		cur->next = NULL;
		free(cur);
		return 1;
	}

	for (; cur; cur = cur->next)//중간 혹은 마지막 데이터 삭제
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

	printf("ERROR: %d isn't exist\n", data);
	return -1;
}

void research_List(int data)//데이터 검색
{
	NODE* cur;
	int check = 0, idx = 1;
	for (cur = head; cur; cur = cur->next)
	{
		if (cur->data == data)
		{
			check = 1;
			break;
		}
		idx++;
	}
	if (check) printf("%d is exist and it's index is %d\n", data, idx);
	else printf("%d isn's exist\n", data);
}

void Print_List()//데이터 출력
{
	NODE* ptr;
	for (ptr = head; ptr->next; ptr = ptr->next)
	{
		printf("%d->", ptr->data);
	}
	printf("%d\n", ptr->data);
}

int main()
{
	init();
	Insert(1);
	Insert(2);
	Insert(5);
	Insert(8);
	Insert(4);
	Print_List();

	return 0;
}