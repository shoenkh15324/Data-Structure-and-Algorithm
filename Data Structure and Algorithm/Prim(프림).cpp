#define _CRT_SECURE_NO_WARNINGS

// 1.������ ������ �������� �����ϰ�, �� ������ MST�� ���Խ�ŵ�ϴ�.
// 2.MST�� ���Ե� ������ ���Ե��� ���� �������� �����ϴ� ���� �߿��� �ּ� ����ġ�� ���� ������ �����մϴ�.
// 3.������ �������� ����� ������ MST�� ���Խ�ŵ�ϴ�.
// 4.��� ������ MST�� ���Ե� ������ 2�ܰ�� 3�ܰ踦 �ݺ��մϴ�.

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

    // ����� �׷������ �Ʒ� �ּ� ����
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
    // �׷��� ���� �� ���� �߰� ����
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    // ���� �˰������� MST ����
    Graph* mst = primMST(graph);

    // MST ���
    printf("Minimum Spanning Tree:\n");
    printMST(mst);

    // �׷����� MST�� �޸� ����
    freeGraph(graph);
    freeGraph(mst);

    return 0;
}