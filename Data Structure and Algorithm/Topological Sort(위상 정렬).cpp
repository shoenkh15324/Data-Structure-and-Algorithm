#define _CRT_SECURE_NO_WARNINGS

//유향 그래프(Directed Acyclic Graph, DAG)에서 정점(Vortex)들을 선형적으로 정렬하는 알고리즘
//순서가 정해져있는 작업을 차례로 수행해야 할 때 그 순서를 결정해 주기 위해 사용하는 알고리즘
//사이클이 발생하는 경우 위상 정렬 알고리즘 사용 불가(시작점을 찾을 수 없기 때문)

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node
{
	int vertex;
	struct Node* next;
} Node;

typedef struct Graph
{
	int numVertices;
	Node* adjLists[MAX_VERTICES];
} Graph;

Node* createNode(int dest)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = dest;
	newNode->next = NULL;
	return newNode;
}

Graph* createGraph(int vertices)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->numVertices = vertices;
	for (int i = 0; i < vertices; i++)
		graph->adjLists[i] = NULL;
	return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
	Node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;
}

int isCyclicUtil(int v, int visited[], int recStack[], Graph* graph) {
	if (visited[v] == 0) {
		visited[v] = 1;
		recStack[v] = 1;

		Node* temp = graph->adjLists[v];
		while (temp) {
			int adjVertex = temp->vertex;
			if (!visited[adjVertex] && isCyclicUtil(adjVertex, visited, recStack, graph))
				return 1;
			else if (recStack[adjVertex])
				return 1;
			temp = temp->next;
		}
	}
	recStack[v] = 0;
	return 0;
}

int isCyclic(Graph* graph) {
	int visited[MAX_VERTICES] = { 0 };
	int recStack[MAX_VERTICES] = { 0 };

	for (int i = 0; i < graph->numVertices; i++) {
		if (isCyclicUtil(i, visited, recStack, graph))
			return 1;
	}
	return 0;
}

void topologicalSortUtil(int v, int visited[], Graph* graph, Node** stack)
{
	visited[v] = 1;
	Node* temp = graph->adjLists[v];
	while (temp)
	{
		int adjVertex = temp->vertex;
		if (!visited[adjVertex])
			topologicalSortUtil(adjVertex, visited, graph, stack);
		temp = temp->next;
	}
	Node* newNode = createNode(v);
	newNode->next = *stack;
	*stack = newNode;
}

void topologicalSort(Graph* graph)
{
	if (isCyclic(graph)) {
		printf("Cannot perform topological sort on a cyclic graph.\n");
		return;
	}

	int visited[MAX_VERTICES] = { 0 };
	Node* stack = NULL;

	for (int i = 0; i < graph->numVertices; i++)
	{
		if (!visited[i])
			topologicalSortUtil(i, visited, graph, &stack);
	}

	printf("Topological Order: ");
	while (stack != NULL)
	{
		printf("%d ", stack->vertex);
		Node* temp = stack;
		stack = stack->next;
		free(temp);
	}
	printf("\n");
}

void freeGraph(Graph* graph) {
	for (int i = 0; i < graph->numVertices; i++) {
		Node* temp = graph->adjLists[i];
		while (temp != NULL) {
			Node* prev = temp;
			temp = temp->next;
			free(prev);
		}
	}
	free(graph);
}

int main()
{
	int vertices, edges;
	printf("Enter the number of vertices and edges: ");
	scanf("%d %d", &vertices, &edges);

	Graph* graph = createGraph(vertices);

	printf("Enter %d edges in the format (source destineation):\n", edges);
	for (int i = 0; i < edges; i++)
	{
		int src, dest;
		scanf("%d %d", &src, &dest);
		addEdge(graph, src, dest);
	}

	topologicalSort(graph);
	freeGraph(graph);

	return 0;
}