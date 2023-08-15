#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* left;
	struct _Node* right;
}NODE;

#define Queue_size 100

typedef NODE* element;//NODE*를  element로 치환
typedef struct//배열 원형 큐의 노드
{
	element data[Queue_size];//NODE* DATA[Queue_size]->큐에 들어갈 데이터 타입이 트리의 노드
	int front, rear;
}Queue;

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
			printf("동일한 값은 허용되지 않음\n");
			return;
		}
	}
}

void Delete(int value)
{
	if (root == NULL)
	{
		printf("ERROR: tree is empty\n");
		return;
	}

	NODE* cur = root;//삭제할 노드
	NODE* parent = NULL;//삭제할 노드의 부모 노드
	NODE* sub_parent = NULL;//sub의 부모 노드
	NODE* sub = NULL;//삭제할 노드의 왼쪽 서브트리에서 가장 큰 노드
	NODE* child = NULL;

	while (cur)
	{
		if (cur->data == value)
			break;
		parent = cur;
		if (value < cur->data)
			cur = cur->left;
		else if (value > cur->data)
			cur = cur->right;
	}

	if (cur == NULL)
	{
		printf("ERROR: %d is not exist\n", value);
		return;
	}

	if (cur->left == NULL && cur->right == NULL)//삭제할 노드가 자식이 없는 경우
	{
		if (parent == NULL)//루트 노드일 경우
		{
			root = NULL;
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
		sub_parent = cur;
		sub = cur->left;

		while (sub->right != NULL)
		{
			sub_parent = sub;
			sub = sub->right;
		}

		if (sub_parent->right == sub)
			sub_parent->right = sub->right;
		else
			sub_parent->left = sub->left;

		cur->data = sub->data;
		cur = sub;
	}
	else
	{
		if (cur->left != NULL)
			child = cur->left;
		else
			child = cur->right;

		if (parent->right == cur)
		{
			parent->right = child;
		}
		else
			parent->left = child;
	}


	free(cur);
	return;
}

void Print_preorder(NODE* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	Print_preorder(root->left);
	Print_preorder(root->right);
}
//큐 함수 구현

void Init_Q(Queue* q)
{
	q->front = q->rear = 0;
}

int isEmpty(Queue* q)
{
	return (q->front == q->rear);
}

int isFull(Queue* q)
{
	return (q->front == (q->rear + 1) % Queue_size);
}

void Enqueue(Queue* q, element item)
{
	if (isFull(q))
	{
		printf("ERROR: Q is Full\n");
		return;
	}
	q->rear = (q->rear + 1) % Queue_size;
	q->data[q->rear] = item;
}

element Dequeue(Queue* q)
{
	if (isEmpty(q))
	{
		printf("ERROR: Queue is empty\n");
		return;
	}
	q->front = (q->front + 1) % Queue_size;
	return q->data[q->front];
}

void levelorder(NODE* ptr)
{
	Queue q;
	Init_Q(&q);
	if (ptr == NULL) return;
	Enqueue(&q, ptr);
	while (!isEmpty(&q))
	{
		ptr = Dequeue(&q);
		printf("%d ", ptr->data);
		if (ptr->left) Enqueue(&q, ptr->left);
		if (ptr->right) Enqueue(&q, ptr->right);
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
	Print_preorder(root);
	printf("\n");
	Delete(15);
	Print_preorder(root);
	printf("\n");
	levelorder(root);

	return 0;
}