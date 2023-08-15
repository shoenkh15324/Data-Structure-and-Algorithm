#define _CRT_SECURE_NO_WARNINGS

//���� ����ġ�� ���� ���� �׷����� ó�� ����, ���� ����Ŭ�� ����ߵ�
//��� �������� ��� ���������� �ִ� ��θ� ���ϴ� ���� ��� ���
//���� ���α׷����� ����Ͽ� ��� ���� �� ���� �ִ� �Ÿ��� ����ϴ� ���. 
//�� ������ ���İ��� ��츦 ����Ͽ� �ִ� �Ÿ��� ����. �ð� ���⵵�� O(V^3)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 999999 // ���Ѵ� ������ ���
#define MAX_VERTICES 10

// �� ������ ���� ������ ��Ÿ���� ����ü
typedef struct Edge
{
    int dest; // ������ ����
    int weight; // ����ġ (�Ÿ�)
    struct Edge* next; // ���� ���� ������ ����Ű�� ������
} Edge;

// �� ������ ��Ÿ���� ����ü
typedef struct Vertex
{
    int value; // ������ ��
    Edge* edges; // ������ ����� �������� ���� ����Ʈ
} Vertex;

// �׷����� ��Ÿ���� ����ü
typedef struct Graph
{
    Vertex* vertices; // �������� �迭
    int num_vertices; // ������ ����
} Graph;

void floydWarshall(Graph* graph) {
    int numVertices = graph->num_vertices;
    int dist[MAX_VERTICES][MAX_VERTICES];

    // �ʱ�ȭ
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }

        Edge* edge = graph->vertices[i].edges;
        while (edge != NULL) {
            dist[i][edge->dest] = edge->weight;
            edge = edge->next;
        }
    }

    // �÷��̵�-�ͼ� �˰��� ����
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // ��� ���
    printf("Shortest paths between all pairs of vertices:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (dist[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%3d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

// ���ο� ������ �����ϴ� �Լ�
Edge* createEdge(int dest, int weight)
{
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->dest = dest;
    new_edge->weight = weight;
    new_edge->next = NULL;
    return new_edge;
}

// �׷����� �����ϴ� �Լ�
Graph* createGraph(int num_vertices)
{
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));
    new_graph->num_vertices = num_vertices;
    new_graph->vertices = (Vertex*)malloc(num_vertices * sizeof(Vertex));

    for (int i = 0; i < num_vertices; i++)
    {
        new_graph->vertices[i].value = i;
        new_graph->vertices[i].edges = NULL;
    }

    return new_graph;
}

// ������ �߰��ϴ� �Լ�
void addEdge(Graph* graph, int src, int dest, int weight)
{
    Edge* new_edge = createEdge(dest, weight);
    new_edge->next = graph->vertices[src].edges;
    graph->vertices[src].edges = new_edge;
}

void free_graph(Graph* graph, int num_vertices)
{
    // �׷��� �޸� ����
    for (int i = 0; i < num_vertices; i++)
    {
        Edge* edge = graph->vertices[i].edges;
        while (edge != NULL)
        {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph->vertices);
    free(graph);
}

int main() {
    int num_vertices = 5;
    Graph* graph = createGraph(num_vertices);

    // ���� �׷��� ����
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    int start_vertex = 0;
    floydWarshall(graph);

    free_graph(graph, num_vertices);

    return 0;
}