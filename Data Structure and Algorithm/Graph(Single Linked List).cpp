#define _CRT_SECURE_NO_WARNINIGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
int v_num = 0;//number of vertex

typedef struct _Node
{
	int n_data;
	struct _Node* next;
}NODE;

typedef struct _Head
{
	int v_data;
	NODE* head;
}VERTEX;

VERTEX* vertex;
int idx = 0;//vertex의 인덱스 순서

void init()
{
	if (v_num == 0) return;

	vertex = (VERTEX*)malloc(sizeof(VERTEX) * v_num);
	for (int i = 0; i < v_num; i++)
	{
		vertex[i].head = NULL;
		vertex[i].v_data = 0;
	}
}

void insert_vertex(int value)
{
	if (v_num == 0) return;
	else if (v_num <= idx) return;
	else vertex[idx++].v_data = value;
}

void insert_edge(int begin, int end)
{
	for (int i = 0; i < v_num; i++)
	{
		if (vertex[i].v_data == begin)
		{
			NODE* newNODE = (NODE*)malloc(sizeof(NODE));
			newNODE->n_data = end;
			newNODE->next = NULL;
			if (vertex[i].head == NULL)
			{
				vertex[i].head = newNODE;
			}
			else
			{
				NODE* ptr = vertex[i].head;
				while (ptr->next)
					ptr = ptr->next;
				ptr->next = newNODE;
			}
		}
	}

	for (int i = 0; i < v_num; i++)
	{
		if (vertex[i].v_data == end)
		{
			NODE* newNODE = (NODE*)malloc(sizeof(NODE));
			newNODE->n_data = begin;
			newNODE->next = NULL;
			if (vertex[i].head == NULL)
			{
				vertex[i].head = newNODE;
			}
			else
			{
				NODE* ptr = vertex[i].head;
				while (ptr->next)
					ptr = ptr->next;
				ptr->next = newNODE;
			}
		}
	}
}

void delete_edge(int begin, int end)
{
	for (int i = 0; i < v_num; i++)
	{
		if (vertex[i].v_data == begin)
		{
			NODE* ptr = vertex[i].head;
			NODE* prev = NULL;
			if (ptr == vertex[i].head)
			{
				vertex[i].head = ptr->next;
				free(ptr);
				return;
			}
			while (ptr)
			{
				if (ptr->n_data == end)
				{
					prev->next = ptr->next;
					free(ptr);
					return;
				}
				else
				{
					prev = ptr;
					ptr = ptr->next;
				}
			}
		}
	}

	for (int i = 0; i < v_num; i++)
	{
		if (vertex[i].v_data == end)
		{
			NODE* ptr = vertex[i].head;
			NODE* prev = NULL;
			if (ptr == vertex[i].head)
			{
				vertex[i].head = ptr->next;
				free(ptr);
				return;
			}
			while (ptr)
			{
				if (ptr->n_data == begin)
				{
					prev->next = ptr->next;
					free(ptr);
					return;
				}
				else
				{
					prev = ptr;
					ptr = ptr->next;
				}
			}
		}
	}
}

void print_graph()
{
	for (int i = 0; i < v_num; i++)
	{
		printf("[ %c ]", vertex[i].v_data + 64);
		NODE* ptr = vertex[i].head;
		while (ptr)
		{
			printf("->%c", ptr->n_data + 64);
			ptr = ptr->next;
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	printf("생성할 정점(Vortex)의 갯수를 입력하세요: \n");
	scanf_s("%d", &v_num);
	init();

	for (int i = 1; i <= 5; i++)
	{
		insert_vertex(i);
	}

	insert_edge(1, 2);
	insert_edge(2, 4);
	insert_edge(1, 3);

	print_graph();

	delete_edge(1, 2);

	print_graph();

	return 0;
}