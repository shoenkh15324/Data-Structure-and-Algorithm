#define _CRT_SECURE_NO_WARNINGS

// MST는 가중치가 있는 그래프에서 모든 정점을 포함하면서 가장 적은 비용으로 연결된 트리(가장 적은 비용으로 모든 노드를 연결하는 알고리즘).
// 크루스칼 알고리즘은 그리디 알고리즘으로, 간선들의 가중치를 오름차순으로 정렬한 후.
// 작은 가중치부터 순서대로 선택하여 사이클을 형성하지 않으면 해당 간선을 MST에 추가하는 방식으로 동작.

#include<stdio.h>
#include<stdlib.h>

// 그래프의 간선을 나타내는 연결 리스트 노드
typedef struct EdgeNode
{
	int src; // 출발 정점
	int dest; // 도착 정점
	int weight; // 가중치
	struct EdgeNode* next;
} EdgeNode;

// 그래프
typedef struct Graph
{
	int V; // 정점의 개수
	EdgeNode* edges; // 간선들의 연결 리스트를 담을 포인터
} Graph;

// 그래프 초기화
Graph* createGraph(int V)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->edges = NULL;
	return graph;
}

// 간선 추가 (연결 리스트에 노드 추가)
void addEdge(Graph* graph, int src, int dest, int weight)
{
	EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
	newNode->src = src;
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = graph->edges;
	graph->edges = newNode;
}

// 부모 정점을 찾는 함수 (유니온 파인드)
int find(int parent[], int i)
{
	if (parent[i] == i)
		return i;
	return find(parent, parent[i]);
}

// 두 정점을 합치는 함수 (유니온 파인드)
void unionVertices(int parent[], int x, int y)
{
	int xroot = find(parent, x);
	int yroot = find(parent, y);
	parent[xroot] = yroot;
}

// 크루스칼 알고리즘
void kruscal(Graph* graph)
{
	int V = graph->V;
	int mstEdges = 0;
	EdgeNode* mst = NULL; // 최소 비용 신장 트리를 담을 연결 리스트
	int* parent = (int*)malloc(sizeof(int));

	// 각 정점을 자기 자신으로 초기화
	for (int i = 0; i < V; i++)
		parent[i] = i;

	// 그래프의 간선들을 가중치를 기준으로 오름차순으로 정렬
	EdgeNode* edge = graph->edges; // 그래프의 간선 목록에서 첫번째 간선을 가리키는 포인터 'edge'를 초기화 
	while (edge != NULL) // edge가 NULL이 될 때까지 각 간선을 하나씩 처리
	{
		EdgeNode* nextEdge = edge->next; // 다음 간선을 임시 변수 nextEdge에 저장
		edge->next = NULL; // 현재 간선을 그래프에서 분리(MST를 구성하기 위해 간선을 재배열하기 때문)
		EdgeNode* prev = NULL; //MST에서 이전 간선을 추적하는데 사용
		EdgeNode* cur = mst; // MST를 순회하고 현재 간선을 올바른 위치에 삽입하기 위해 사용
		while (cur != NULL && edge->weight > cur->weight) // MST의 현재 간선의 올바른 위치를 찾기위해 MST를 순회
		{
			prev = cur;
			cur = cur->next;
		}
		if (prev == NULL) // prev가 NULL이라면, 현재 간선은 MST의 모든 간선 중 가중치가 가장 작다.
			mst = edge;
		else
			prev->next = edge;
		edge->next = cur;
		edge = nextEdge;
	}

	// 최소 비용 신장 트리 구성
	EdgeNode* currEdge = mst;
	while (currEdge != NULL)
	{
		int x = find(parent, currEdge->src);
		int y = find(parent, currEdge->dest);

		// 사이클을 형성하지 않으면 해당 간선을 MST에 추가
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