#include <stdio.h>
#include <stdlib.h>

//이진 탐색 트리

typedef struct _Node
{
	int data;
	struct _Node* left;
	struct _Node* right;
}NODE;

NODE* root = NULL;

NODE* insert(NODE* root, int value)
{
	NODE* ptr;//탐색을 진행할 포인터
	NODE* newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->data = value;
	newNODE->left = NULL, newNODE->right = NULL;

	if (root == NULL)
	{
		root = newNODE;
		return root;
	}

	ptr = root;

	while (ptr)
	{
		if (ptr->data == value)
		{
			printf("ERROR: The same value is not allowed\n");
			return root;
		}
		else if (ptr->data > value)
		{
			if (ptr->left == NULL)
			{
				ptr->left = newNODE;
				newNODE->data = value;
				return root;
			}
			else
				ptr = ptr->left;
		}
		else
		{
			if (ptr->right == NULL)
			{
				ptr->right = newNODE;
				newNODE->data = value;
				return root;
			}
			else
				ptr = ptr->right;
		}
	}
}

NODE* fMin(NODE* root)
{
	NODE* min = root;
	while (min->left != NULL)
		min = min->left;
	return min;
}

NODE* DeleteNode(NODE* root, int value)
{
	NODE* tmproot = NULL;

	if (root == NULL)
	{
		printf("ERROR: Tree is empty\n");
		return root;
	}
	if (value < root->data)
		root->left = DeleteNode(root->left, value);
	else if (value > root->data)
		root->right = DeleteNode(root->right, value);
	else
	{
		if (root->left != NULL || root->right != NULL)
		{
			tmproot = fMin(root->right);
			root->data = tmproot->data;
			root->right = DeleteNode(root->right, tmproot->data);
		}
		else
		{
			tmproot = (root->left != NULL) ? root->right : root->left;
			free(root);
			return tmproot;
		}
	}
	return root;
}

void print(NODE* root)//preorder
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	print(root->left);
	print(root->right);
}

//void Preoder_Print(NODE* root)
//{
//	if (root == NULL)
//	{
//		printf("ERROR: Tree is empty\n");
//		return;
//	}
//	printf("%d ", root->data);
//	print(root->left);
//	print(root->right);
//}
//
//void Inoder_Print(NODE* root)
//{
//	if (root == NULL)
//	{
//		printf("ERROR: Tree is empty\n");
//		return;
//	}
//	print(root->left);
//	printf("%d ", root->data);
//	print(root->right);
//}
//
//void Postoder_Print(NODE* root)
//{
//	if (root == NULL)
//	{
//		printf("ERROR: Tree is empty\n");
//		return;
//	}
//	print(root->left);
//	print(root->right);
//	printf("%d ", root->data);
//}

NODE* Search(NODE* root, int value)
{
	if (root == NULL)
	{
		printf("ERROR: %d is not exist", value);
		return root;
	}
	if (root->data == value)
	{
		printf("%d is exist", value);
		return root;
	}
	else if (value < root->data)
		Search(root->left, value);
	else if (value > root->data)
		Search(root->right, value);
}

int main()
{
	root = insert(root, 7);
	root = insert(root, 3);
	root = insert(root, 8);
	root = insert(root, 1);
	root = insert(root, 5);
	root = insert(root, 4);
	root = insert(root, 10);

	print(root);

	printf("\n");

	root = DeleteNode(root, 7);

	print(root);

	return 0;
}