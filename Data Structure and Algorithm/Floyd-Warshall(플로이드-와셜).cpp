#define _CRT_SECURE_NO_WARNINGS

//음의 가중치를 갖는 가중 그래프도 처리 가능, 음의 사이클이 없어야됨
//모든 정점에서 모든 정점으로의 최단 경로를 구하는 싶은 경우 사용
//동적 프로그래밍을 사용하여 모든 정점 쌍 간의 최단 거리를 계산하는 방식. 
//각 정점을 거쳐가는 경우를 고려하여 최단 거리를 갱신. 시간 복잡도는 O(V^3)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 999999 // 무한대 값으로 사용
#define MAX_VERTICES 10

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

void floydWarshall(Graph* graph) {
    int numVertices = graph->num_vertices;
    int dist[MAX_VERTICES][MAX_VERTICES];

    // 초기화
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

    // 플로이드-와셜 알고리즘 수행
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 결과 출력
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
    floydWarshall(graph);

    free_graph(graph, num_vertices);

    return 0;
}