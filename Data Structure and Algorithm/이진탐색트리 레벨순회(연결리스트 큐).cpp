#include <stdio.h>
#include <stdlib.h>

typedef struct _TREENODE
{
	int data;
	struct _TREENODE* left, * right;
}NODE;

typedef struct _QNODE
{
	NODE* data;
	struct _QNODE* next;
}QUEUE;

NODE* root = NULL;

void Insert(int value)
{
	NODE* newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->data = value;
	newNODE->left = NULL, newNODE->right = NULL;

	if (root == NULL)
	{
		root = newNODE;
		return;
	}
	NODE* ptr = root;
	while (ptr)
	{
		if (ptr->data == value)
		{
			printf("ERROR: the same value is not allowed\n");
			return;
		}
		else
		{
			if (value < ptr->data)
			{
				if (ptr->left == NULL)
				{
					ptr->left = newNODE;
					return;
				}
				else
					ptr = ptr->left;
			}
			else
			{
				if (ptr->right == NULL)
				{
					ptr->right = newNODE;
					return;
				}
				else
					ptr = ptr->right;
			}
		}
	}
}

void Delete(int value)
{
	if (root == NULL)
	{
		printf("ERROR: Tree is empty\n");
		return;
	}

	NODE* cur = root;
	NODE* parent = NULL;


	while (cur)
	{
		if (cur->data == value)
			break;
		parent = cur;
		if (value < cur->data) cur = cur->left;
		else cur = cur->right;
	}
	if (cur == NULL)
	{
		printf("ERROR: %d is not exist\n", value);
		return;
	}
	else
	{
		if (cur->left == NULL && cur->right == NULL)
		{
			if (parent == NULL)
			{
				printf("ERROR: Tree is empty\n");
				return;
			}
			else
			{
				if (parent->left == cur)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
		}
		else if (cur->left != NULL && cur->right != NULL)
		{
			NODE* max = NULL;
			NODE* max_p = NULL;

			max_p = cur;
			max = cur->left;

			while (max->right != NULL)
			{
				max_p = max;
				max = max->right;
			}

			if (max_p->left == max)
				max_p->left = max->left;
			else
				max_p->right = max->left;

			cur->data = max->data;
			cur = max;
		}
		else
		{
			NODE* child = NULL;

			if (cur->left == NULL)
				child = cur->right;
			else
				child = cur->left;

			if (parent == NULL)
				root = child;
			else
			{
				if (parent->left = cur)
					parent->left = child;
				else
					parent->right = child;
			}
		}
	}
	free(cur);
	return;
}

void Preorder(NODE* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

//
QUEUE* head;
void Init()
{
	QUEUE* head = NULL;
}

void Enqueue(NODE* root)
{
	QUEUE* newQnode = (QUEUE*)malloc(sizeof(QUEUE));
	newQnode->data = root;
	newQnode->next = NULL;

	if (head == NULL)
	{
		head = newQnode;
		return;
	}
	else
	{
		QUEUE* ptr = head;
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = newQnode;
		return;
	}
}

NODE* Dequeue()
{
	if (head == NULL)
	{
		return NULL;
	}

	QUEUE* ptr = head;
	QUEUE* tmp = NULL;

	if (ptr->next)
		head = ptr->next;
	else
		head = NULL;

	ptr->next = NULL;
	tmp = ptr->data;
	free(ptr);
	return tmp;
}

void Levelorder(NODE* root)
{
	Init();
	Enqueue(root);
	while (root)
	{
		root = Dequeue();
		if (root == NULL)
		{
			break;
		}
		printf("%d ", root->data);
		if (root->left) Enqueue(root->left);
		if (root->right) Enqueue(root->right);
	}
}

int main()
{
	Insert(7);
	Insert(3);
	Insert(8);
	Insert(1);
	Insert(5);
	Insert(4);
	Insert(10);
	Preorder(root);
	printf("\n");
	Delete(7);
	Preorder(root);
	printf("\n");
	Levelorder(root);

	return 0;
}