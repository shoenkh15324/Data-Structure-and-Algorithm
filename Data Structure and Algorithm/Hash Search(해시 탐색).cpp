#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 10

// �ؽ� ��� ����ü
struct HashNode
{
	int key;
	int value;
	struct HashNode* next;
};

// �ؽ� ���̺� ����ü
struct HashTable
{
	HashNode* table[HASH_TABLE_SIZE];
};

int hashFunction(int key)
{
	return key % HASH_TABLE_SIZE;
}

void insert(HashTable* ht, int key, int value)
{
	int hashValue = hashFunction(key);

	HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	if (ht->table[hashValue] == NULL)
	{
		ht->table[hashValue] = newNode;
	}
	else
	{
		//ü�̴�(Chaining)�� ����Ͽ� �浹 ����
		HashNode* temp = ht->table[hashValue];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int search(HashTable* ht, int key)
{
	int hashValue = hashFunction(key);

	HashNode* temp = ht->table[hashValue];
	while (temp != NULL)
	{
		if (temp->key == key)
		{
			return temp->value;
		}
		temp = temp->next;
	}
	return -1;
}

int main()
{
	HashTable ht;

	for (int i = 0; i < HASH_TABLE_SIZE; i++)
		ht.table[i] = NULL;

	insert(&ht, 42, 10);
	insert(&ht, 7, 20);
	insert(&ht, 23, 30);

	int result = search(&ht, 7);

	if (result != -1)
		printf("Ű 7�� �ش��ϴ� ��: %d\n", result);
	else
		printf("Ű 7�� ã�� ���߽��ϴ�.\n");

	return 0;
}