#include <stdio.h>
#include <stdlib.h>

//������ �����͸� ������������ �����ϴ� ���� ���Ḯ��Ʈ

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

	//����Ʈ�� ���������
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		if (head->data > newNode->data)//�� �տ� �߰�
		{
			newNode->next = head;
			head = newNode;
			return;
		}

		for (ptr = head; ptr->next; ptr = ptr->next)//�߰��� �߰�
		{
			if (ptr->data <newNode->data && ptr->next->data > newNode->data)
			{
				newNode->next = ptr->next;
				ptr->next = newNode;
				return;
			}
		}

		ptr->next = newNode;//�� ���� �߰�
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

	if (head->data == data)//�� ó�� ������ ����
	{
		head = cur->next;
		cur->next = NULL;
		free(cur);
		return 1;
	}

	for (; cur; cur = cur->next)//�߰� Ȥ�� ������ ������ ����
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

void research_List(int data)//������ �˻�
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

void Print_List()//������ ���
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