#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
	char data;
	struct _Node* next;
}NODE;

NODE* head;
void Init()
{
	head = NULL;
}

void InsertNode(char str)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = str;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		NODE* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int DeleteNode(char str)
{
	NODE* cur, * prev;
	cur = prev = head;

	if (head == NULL)
	{
		printf("ERROR: list is empty!\n");
		return -1;
	}

	if (head->data == (int)str)
	{
		head = cur->next;
		cur->next = NULL;
		free(cur);
		return 1;
	}

	for (; cur; cur = cur->next)
	{
		if (cur->data == (int)str)
		{
			prev->next = cur->next;
			cur->next = NULL;
			free(cur);
			return 1;
		}
		prev = cur;
	}

	printf("ERROR: there is no %c\n", str);
	return -1;
}

void Search(char str)
{
	NODE* cur;
	int check = 0;
	for (cur = head; cur->next; cur = cur->next)
	{
		if (cur->data == (int)str)
		{
			check = 1;
			break;
		}
	}
	if (check == 1)
		printf("'%c' is exist!\n", str);
	else
		printf("'%c' is not exist!\n", str);
}

void PrintList()
{
	NODE* cur;
	for (cur = head; cur->next; cur = cur->next)
	{
		printf("%c->", cur->data);
	}
	printf("%c\n", cur->data);
}

int main()
{
	Init();
	char word[20] = "hello";


	for (int i = 0; i < strlen(word); i++)
	{
		InsertNode(word[i]);
	}
	PrintList();
	DeleteNode('l');
	PrintList();
	DeleteNode('a');
	PrintList();
	Search('l');

	return 0;
}