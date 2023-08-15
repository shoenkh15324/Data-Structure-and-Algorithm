#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* left;
	struct _Node* right;
}NODE;

NODE* root = NULL;

void Insert(int value)
{

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
	{
		root = newNode;
		return;
	}
	NODE* ptr = root;
	while (ptr)
	{
		if (value < ptr->data)
		{
			if (ptr->left == NULL)
			{
				ptr->left = newNode;
				return;
			}
			else
				ptr = ptr->left;
		}
		else if (value > ptr->data)
		{
			if (ptr->right == NULL)
			{
				ptr->right = newNode;
				return;
			}
			else
				ptr = ptr->right;
		}
		else
		{
			printf("ERROE: same value is not allowed\n");
			return;
		}
	}
}

void Delete(int value)
{
	if (root->data == NULL)
	{
		printf("ERROR: tree is empty\n");
		return;
	}
	NODE* cur = root;//삭제할 노드
	NODE* parent = NULL;//삭제할 노드의 부모 노드
	NODE* predecessor = NULL;//successor의 부모 노드
	NODE* successor = NULL;//삭제할 노드의 왼쪽 서브트리에서 가장 큰 노드
	NODE* child = NULL;//삭제할 노드의 자식 노드

	while (cur)
	{
		if (cur->data == value)
			break;
		parent = cur;
		if (value < cur->data)
			cur = cur->left;
		else
			cur = cur->right;
	}

	if (cur == NULL)
	{
		printf("ERROR: %d is not exist\n");
		return;
	}

	if (cur->left == NULL && cur->right == NULL)//삭제할 노드의 자식노드가 없는 경우
	{
		if (parent != NULL)//삭제할 노드가 루트노드가 아닐 경우
		{
			if (parent->left = cur)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;//삭제할 노드가 루트노드일 경우
	}
	else if (cur->left != NULL && cur->right != NULL)//삭제할 노드의 자식노드가 2개인 경우
	{
		predecessor = cur;
		successor = cur->left;

		while (successor->right)
		{
			predecessor = successor;
			successor = successor->right;
		}

		if (predecessor->left == successor)
			predecessor->left = successor->left;
		else
			predecessor->right = successor->left;

		cur->data = successor->data;
		cur = successor;
	}
	else//자식 노드가 1개일 경우
	{
		if (cur->left != NULL)
			child = cur->left;
		else
			child = cur->right;

		if (parent == NULL)
		{
			root = child;
		}
		else
		{
			if (parent->left == cur)
				parent->left = child;
			else
				parent->right = child;
		}
	}

	free(cur);
	return;
}

void Print_preorder(NODE* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	Print_preorder(root->left);
	Print_preorder(root->right);
}

void Print_inorder(NODE* root)
{
	if (root == NULL)
		return;
	Print_inorder(root->left);
	printf("%d ", root->data);
	Print_inorder(root->right);
}

void Print_postorder(NODE* root)
{
	if (root == NULL)
		return;
	Print_postorder(root->left);
	Print_postorder(root->right);
	printf("%d ", root->data);
}

void Search(int value)
{
	NODE* ptr = root;
	int check = 0;
	while (ptr)
	{
		if (ptr->data == value)
		{
			check = 1;
			break;
		}
		else if (value < ptr->data)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	if (check == 1)
		printf("%d is exist\n", value);
	else
		printf("%d is not exist\n", value);
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
	Print_preorder(root);
	printf("\n");
	Print_inorder(root);
	printf("\n");
	Print_postorder(root);
	Search(8);
	Search(11);

	return 0;
}