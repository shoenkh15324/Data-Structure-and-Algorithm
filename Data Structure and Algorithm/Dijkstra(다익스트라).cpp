#define _CRT_SECURE_NO_WARNINGS

//음의 가중치, 음의 사이클을 갖지 않는 가중 그래프에서 사용됨.
//하나의 정점에서 다른 모든 정점으로의 최단 경로를 구하는 경우 사용

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 999999 // 무한대 값으로 사용

// 각 정점의 연결 정보를 나타내는 구조체
typedef struct Edge
{
    int dest; // 목적지 정점
    int weight; // 가중치 (거리)
    struct Edge* next; // 다음 연결 정보를 가리키는 포인터
} Edge;

// 각 정점을 나타내는 구조체
typedef struct Vertex
{
    int value; // 정점의 값
    Edge* edges; // 정점과 연결된 간선들의 연결 리스트
} Vertex;

// 그래프를 나타내는 구조체
typedef struct Graph
{
    Vertex* vertices; // 정점들의 배열
    int num_vertices; // 정점의 개수
} Graph;

// 최소 거리를 가지는 정점을 찾는 함수
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

// 다익스트라 알고리즘 함수
void dijkstra(Graph* graph, int start)
{
    int* distance = (int*)malloc(graph->num_vertices * sizeof(int));
    bool* visited = (bool*)malloc(graph->num_vertices * sizeof(bool));

    for (int i = 0; i < graph->num_vertices; i++)
    {
        distance[i] = INF;
        visited[i] = false;
    }

    // 시작 정점의 최단 거리는 0으로 설정
    distance[start] = 0;

    for (int i = 0; i < graph->num_vertices - 1; i++)
    {
        int current_vertex = getMinVertex(distance, visited, graph->num_vertices);
        visited[current_vertex] = true;

        // 현재 정점과 연결된 간선들을 순회하면서 최단 거리를 갱신합니다.
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

    // 최단 거리 출력
    printf("출발 정점으로부터의 최단 거리:\n");
    for (int i = 0; i < graph->num_vertices; i++)
        printf("%d -> %d: %d\n", start, i, distance[i]);

    free(distance);
    free(visited);
}

// 새로운 간선을 생성하는 함수
Edge* createEdge(int dest, int weight)
{
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->dest = dest;
    new_edge->weight = weight;
    new_edge->next = NULL;
    return new_edge;
}

// 그래프를 생성하는 함수
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

// 간선을 추가하는 함수
void addEdge(Graph* graph, int src, int dest, int weight)
{
    Edge* new_edge = createEdge(dest, weight);
    new_edge->next = graph->vertices[src].edges;
    graph->vertices[src].edges = new_edge;
}

void free_graph(Graph* graph, int num_vertices)
{
    // 그래프 메모리 해제
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

    // 예제 그래프 설정
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