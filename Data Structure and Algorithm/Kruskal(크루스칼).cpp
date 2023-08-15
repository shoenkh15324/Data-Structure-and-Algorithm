#define _CRT_SECURE_NO_WARNINGS

// MST�� ����ġ�� �ִ� �׷������� ��� ������ �����ϸ鼭 ���� ���� ������� ����� Ʈ��(���� ���� ������� ��� ��带 �����ϴ� �˰���).
// ũ�罺Į �˰����� �׸��� �˰�������, �������� ����ġ�� ������������ ������ ��.
// ���� ����ġ���� ������� �����Ͽ� ����Ŭ�� �������� ������ �ش� ������ MST�� �߰��ϴ� ������� ����.

#include<stdio.h>
#include<stdlib.h>

// �׷����� ������ ��Ÿ���� ���� ����Ʈ ���
typedef struct EdgeNode
{
	int src; // ��� ����
	int dest; // ���� ����
	int weight; // ����ġ
	struct EdgeNode* next;
} EdgeNode;

// �׷���
typedef struct Graph
{
	int V; // ������ ����
	EdgeNode* edges; // �������� ���� ����Ʈ�� ���� ������
} Graph;

// �׷��� �ʱ�ȭ
Graph* createGraph(int V)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->edges = NULL;
	return graph;
}

// ���� �߰� (���� ����Ʈ�� ��� �߰�)
void addEdge(Graph* graph, int src, int dest, int weight)
{
	EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
	newNode->src = src;
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = graph->edges;
	graph->edges = newNode;
}

// �θ� ������ ã�� �Լ� (���Ͽ� ���ε�)
int find(int parent[], int i)
{
	if (parent[i] == i)
		return i;
	return find(parent, parent[i]);
}

// �� ������ ��ġ�� �Լ� (���Ͽ� ���ε�)
void unionVertices(int parent[], int x, int y)
{
	int xroot = find(parent, x);
	int yroot = find(parent, y);
	parent[xroot] = yroot;
}

// ũ�罺Į �˰���
void kruscal(Graph* graph)
{
	int V = graph->V;
	int mstEdges = 0;
	EdgeNode* mst = NULL; // �ּ� ��� ���� Ʈ���� ���� ���� ����Ʈ
	int* parent = (int*)malloc(sizeof(int));

	// �� ������ �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 0; i < V; i++)
		parent[i] = i;

	// �׷����� �������� ����ġ�� �������� ������������ ����
	EdgeNode* edge = graph->edges; // �׷����� ���� ��Ͽ��� ù��° ������ ����Ű�� ������ 'edge'�� �ʱ�ȭ 
	while (edge != NULL) // edge�� NULL�� �� ������ �� ������ �ϳ��� ó��
	{
		EdgeNode* nextEdge = edge->next; // ���� ������ �ӽ� ���� nextEdge�� ����
		edge->next = NULL; // ���� ������ �׷������� �и�(MST�� �����ϱ� ���� ������ ��迭�ϱ� ����)
		EdgeNode* prev = NULL; //MST���� ���� ������ �����ϴµ� ���
		EdgeNode* cur = mst; // MST�� ��ȸ�ϰ� ���� ������ �ùٸ� ��ġ�� �����ϱ� ���� ���
		while (cur != NULL && edge->weight > cur->weight) // MST�� ���� ������ �ùٸ� ��ġ�� ã������ MST�� ��ȸ
		{
			prev = cur;
			cur = cur->next;
		}
		if (prev == NULL) // prev�� NULL�̶��, ���� ������ MST�� ��� ���� �� ����ġ�� ���� �۴�.
			mst = edge;
		else
			prev->next = edge;
		edge->next = cur;
		edge = nextEdge;
	}

	// �ּ� ��� ���� Ʈ�� ����
	EdgeNode* currEdge = mst;
	while (currEdge != NULL)
	{
		int x = find(parent, currEdge->src);
		int y = find(parent, currEdge->dest);

		// ����Ŭ�� �������� ������ �ش� ������ MST�� �߰�
		if (x != y)
		{
			unionVertices(parent, x, y);
			printf("%d -- %d : %d\n", currEdge->src, currEdge->dest, currEdge->weight);
		}

		currEdge = currEdge->next;
	}
}

int main()
{
	int	V = 5;
	Graph* graph = createGraph(V);

	addEdge(graph, 2, 1, 1);
	addEdge(graph, 2, 4, 2);
	addEdge(graph, 2, 3, 6);
	addEdge(graph, 1, 5, 3);
	addEdge(graph, 4, 5, 5);
	addEdge(graph, 3, 5, 4);

	kruscal(graph);

	return 0;
}