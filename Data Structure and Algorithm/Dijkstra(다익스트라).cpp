#define _CRT_SECURE_NO_WARNINGS

//���� ����ġ, ���� ����Ŭ�� ���� �ʴ� ���� �׷������� ����.
//�ϳ��� �������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� ��� ���

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 999999 // ���Ѵ� ������ ���

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

// �ּ� �Ÿ��� ������ ������ ã�� �Լ�
int getMinVertex(int distance[], bool visited[], int num_vertices)
{
    int min_distance = INF;
    int min_vertex = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        if (!visited[i] && distance[i] < min_distance)
        {
            min_distance = distance[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

// ���ͽ�Ʈ�� �˰��� �Լ�
void dijkstra(Graph* graph, int start)
{
    int* distance = (int*)malloc(graph->num_vertices * sizeof(int));
    bool* visited = (bool*)malloc(graph->num_vertices * sizeof(bool));

    for (int i = 0; i < graph->num_vertices; i++)
    {
        distance[i] = INF;
        visited[i] = false;
    }

    // ���� ������ �ִ� �Ÿ��� 0���� ����
    distance[start] = 0;

    for (int i = 0; i < graph->num_vertices - 1; i++)
    {
        int current_vertex = getMinVertex(distance, visited, graph->num_vertices);
        visited[current_vertex] = true;

        // ���� ������ ����� �������� ��ȸ�ϸ鼭 �ִ� �Ÿ��� �����մϴ�.
        Edge* edge = graph->vertices[current_vertex].edges;
        while (edge != NULL)
        {
            int next_vertex = edge->dest;
            int new_distance = distance[current_vertex] + edge->weight;
            if (!visited[next_vertex] && new_distance < distance[next_vertex])
                distance[next_vertex] = new_distance;
            edge = edge->next;
        }
    }

    // �ִ� �Ÿ� ���
    printf("��� �������κ����� �ִ� �Ÿ�:\n");
    for (int i = 0; i < graph->num_vertices; i++)
        printf("%d -> %d: %d\n", start, i, distance[i]);

    free(distance);
    free(visited);
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
    dijkstra(graph, start_vertex);

    free_graph(graph, num_vertices);

    return 0;
}