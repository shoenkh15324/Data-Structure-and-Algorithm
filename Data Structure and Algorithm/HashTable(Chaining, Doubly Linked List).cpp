#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

typedef struct _Node
{
	int key;
	int value;
	struct _Node* next;
	struct _Node* prev;
}NODE;

typedef struct _Bucket
{
	NODE* head;
	int count;
}BUCKET;

BUCKET* hashtable = NULL;

void init()
{
	hashtable = (BUCKET*)malloc(sizeof(BUCKET) * BUCKET_SIZE);
	for (int i = 0; i < BUCKET_SIZE; i++)
	{
		hashtable[i].head = NULL;
	}
}

int hashfunction(int key)
{
	return key % BUCKET_SIZE;
}

void add(int key, int value)
{
	int hashindex = hashfunction(key);
	NODE* newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->key = key;
	newNODE->value = value;
	newNODE->next = NULL;
	newNODE->prev = NULL;

	if (hashtable[hashindex].head == NULL)
	{
		hashtable[hashindex].head = newNODE;
		hashtable[hashindex].count = 1;
		return;
	}
	else
	{
		newNODE->next = hashtable[hashindex].head;
		newNODE->next->prev = newNODE;
		hashtable[hashindex].head = newNODE;
		hashtable[hashindex].count++;
		return;
	}
}

void remove_key(int key)
{
	int hashindex = hashfunction(key);
	NODE* ptr = hashtable[hashindex].head;
	int check = 0;
	while (ptr != NULL)
	{
		if (ptr->key == key)
		{
			check = 1;
			if (ptr == hashtable[hashindex].head)
			{
				hashtable[hashindex].head = ptr->next;
			}
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}

		}
		ptr = ptr->next;
	}

	free(ptr);
	hashtable[hashindex].count--;

	if (check == 1)
		printf("\n [ %d ] 이/가 삭제되었습니다. \n", key);
	else
		printf("\n [ %d ] 이/가 존재하지 않아 삭제하지 못했습니다.\n", key);
}

void display()
{
	NODE* iterator;
	printf("\n========= display start ========= \n");
	for (int i = 0; i < BUCKET_SIZE; i++) {
		iterator = hashtable[i].head;
		printf("Bucket[%d] : ", i);
		while (iterator->next != NULL)
		{
			printf("(key : %d, val : %d)  <-> ", iterator->key, iterator->value);
			iterator = iterator->next;
		}
		printf("(key : %d, val : %d)", iterator->key, iterator->value);
		printf("\n");
	}
	printf("\n========= display complete ========= \n");
}

void search(int key)
{
	int hashindex = hashfunction(key);
	NODE* ptr = hashtable[hashindex].head;
	int check = 0;
	while (ptr != NULL)
	{
		if (ptr->key == key)
		{
			check = 1;
			break;
		}
		else
			ptr = ptr->next;
	}
	if (check == 1)
		printf("\n 키는 [ %d ], 값은 [ %d ] 입니다. \n", ptr->key, ptr->value);
	else
		printf("\n 존재하지 않은 키는 찾을 수 없습니다. \n");
}

int main()
{
	init();

	for (int i = 0; i < 16; i++) {
		add(i, 10 * i);
	}

	add(21, 210);
	add(31, 310);
	add(41, 410);

	display();

	remove_key(31);
	remove_key(11);
	remove_key(51);

	display();

	search(21);
	search(31);

	return 0;
}