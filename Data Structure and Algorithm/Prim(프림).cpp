#define _CRT_SECURE_NO_WARNINGS

// 1.임의의 정점을 시작으로 선택하고, 이 정점을 MST에 포함시킵니다.
// 2.MST에 포함된 정점과 포함되지 않은 정점들을 연결하는 간선 중에서 최소 가중치를 가진 간선을 선택합니다.
// 3.선택한 간선으로 연결된 정점을 MST에 포함시킵니다.
// 4.모든 정점이 MST에 포함될 때까지 2단계와 3단계를 반복합니다.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct EdgeNode {
    int src;
    int dest;
    int weight;
    struct EdgeNode* next;
} EdgeNode;

typedef struct Graph {
    int numVertices;
    EdgeNode** adjList;
} Graph;

EdgeNode* createEdge(int src, int dest, int weight) {
    EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
    newEdge->src = src;
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (EdgeNode**)malloc(numVertices * sizeof(EdgeNode*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    EdgeNode* newEdge = createEdge(src, dest, weight);
    newEdge->next = graph->adjList[src];
    graph->adjList[src] = newEdge;

    // 양방향 그래프라면 아래 주석 해제
    // EdgeNode* newEdge2 = createEdge(dest, src, weight);
    // newEdge2->next = graph->adjList[dest];
    // graph->adjList[dest] = newEdge2;
}

Graph* primMST(Graph* graph) {
    Graph* mst = createGraph(graph->numVertices);
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    visited[0] = 1;
    int numEdges = 0;

    while (numEdges < graph->numVertices - 1) {
        int minWeight = INT_MAX;
        EdgeNode* minEdge = NULL;

        for (int i = 0; i < graph->numVertices; i++) {
            if (visited[i]) {
                EdgeNode* edge = graph->adjList[i];
                while (edge != NULL) {
                    if (!visited[edge->dest] && edge->weight < minWeight) {
                        minWeight = edge->weight;
                        minEdge = edge;
                    }
                    edge = edge->next;
                }
            }
        }

        if (minEdge != NULL) {
            addEdge(mst, minEdge->src, minEdge->dest, minEdge->weight);
            visited[minEdge->dest] = 1;
            numEdges++;
        }
    }

    free(visited);
    return mst;
}

void printMST(Graph* mst) {
    for (int i = 0; i < mst->numVertices; i++) {
        EdgeNode* edge = mst->adjList[i];
        while (edge != NULL) {
            printf("%d -> %d (weight: %d)\n", edge->src, edge->dest, edge->weight);
            edge = edge->next;
        }
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        EdgeNode* edge = graph->adjList[i];
        while (edge != NULL) {
            EdgeNode* next = edge->next;
            free(edge);
            edge = next;
        }
    }
    free(graph->adjList);
    free(graph);
}

int main() {
    // 그래프 생성 및 간선 추가 예시
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    // 프림 알고리즘으로 MST 구성
    Graph* mst = primMST(graph);

    // MST 출력
    printf("Minimum Spanning Tree:\n");
    printMST(mst);

    // 그래프와 MST의 메모리 해제
    freeGraph(graph);
    freeGraph(mst);

    return 0;
}