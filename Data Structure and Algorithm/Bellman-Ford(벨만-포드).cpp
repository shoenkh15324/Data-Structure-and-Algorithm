#define _CRT_SECURE_NO_WARNINGS

// 음의 가중치를 갖는 그래프에서도 사용가능
// 각 정점까지의 최단 거리를 최악의 경우, 간선의 개수인 |V| - 1번 반복하면서 업데이트하는 방식. 
// 음수 가중치를 허용하므로, 음수 사이클을 감지할 수 있다. 정점의 개수가 V, 간선의 개수가 E라고 할 때, 시간 복잡도는 O(V * E).

#include <stdio.h>
#include <stdlib.h>

#define INF 999999

// 그래프의 간선을 나타내는 연결 리스트 노드
typedef struct EdgeNode {
    int dest;           // 목적지 정점
    int weight;         // 가중치
    struct EdgeNode* next;
} EdgeNode;

// 정점을 나타내는 연결 리스트의 헤더
typedef struct {
    EdgeNode* head;
} Vertex;

// 그래프
typedef struct {
    int V;              // 정점의 개수
    Vertex* vertices;   // 각 정점의 연결 리스트를 담은 배열
} Graph;

// 그래프 초기화
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->vertices = (Vertex*)malloc(V * sizeof(Vertex));

    for (int i = 0; i < V; i++) {
        graph->vertices[i].head = NULL;
    }

    return graph;
}

// 간선 추가
void addEdge(Graph* graph, int src, int dest, int weight) {
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->vertices[src].head;
    graph->vertices[src].head = newNode;
}

// 벨만-포드 알고리즘
void BellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int));

    // 모든 정점의 거리를 무한대로 초기화
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // V-1번의 반복으로 최단 경로 갱신
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            EdgeNode* edge = graph->vertices[u].head;
            while (edge != NULL) {
                int v = edge->dest;
                int weight = edge->weight;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
                edge = edge->next;
            }
        }
    }

    // 음수 사이클 검사
    for (int u = 0; u < V; u++) {
        EdgeNode* edge = graph->vertices[u].head;
        while (edge != NULL) {
            int v = edge->dest;
            int weight = edge->weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                printf("음수 사이클이 존재합니다.\n");
                return;
            }
            edge = edge->next;
        }
    }

    // 최단 경로 출력
    printf("정점\t거리\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    free(dist);
}

int main() {
    int V = 5; // 정점의 개수
    Graph* graph = createGraph(V);

    // 간선 추가
    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);

    int src = 0; // 시작 정점
    BellmanFord(graph, src);

    return 0;
}