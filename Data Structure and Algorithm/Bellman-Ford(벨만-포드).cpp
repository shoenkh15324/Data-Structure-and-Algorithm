#define _CRT_SECURE_NO_WARNINGS

// ���� ����ġ�� ���� �׷��������� ��밡��
// �� ���������� �ִ� �Ÿ��� �־��� ���, ������ ������ |V| - 1�� �ݺ��ϸ鼭 ������Ʈ�ϴ� ���. 
// ���� ����ġ�� ����ϹǷ�, ���� ����Ŭ�� ������ �� �ִ�. ������ ������ V, ������ ������ E��� �� ��, �ð� ���⵵�� O(V * E).

#include <stdio.h>
#include <stdlib.h>

#define INF 999999

// �׷����� ������ ��Ÿ���� ���� ����Ʈ ���
typedef struct EdgeNode {
    int dest;           // ������ ����
    int weight;         // ����ġ
    struct EdgeNode* next;
} EdgeNode;

// ������ ��Ÿ���� ���� ����Ʈ�� ���
typedef struct {
    EdgeNode* head;
} Vertex;

// �׷���
typedef struct {
    int V;              // ������ ����
    Vertex* vertices;   // �� ������ ���� ����Ʈ�� ���� �迭
} Graph;

// �׷��� �ʱ�ȭ
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->vertices = (Vertex*)malloc(V * sizeof(Vertex));

    for (int i = 0; i < V; i++) {
        graph->vertices[i].head = NULL;
    }

    return graph;
}

// ���� �߰�
void addEdge(Graph* graph, int src, int dest, int weight) {
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->vertices[src].head;
    graph->vertices[src].head = newNode;
}

// ����-���� �˰���
void BellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int));

    // ��� ������ �Ÿ��� ���Ѵ�� �ʱ�ȭ
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // V-1���� �ݺ����� �ִ� ��� ����
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

    // ���� ����Ŭ �˻�
    for (int u = 0; u < V; u++) {
        EdgeNode* edge = graph->vertices[u].head;
        while (edge != NULL) {
            int v = edge->dest;
            int weight = edge->weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                printf("���� ����Ŭ�� �����մϴ�.\n");
                return;
            }
            edge = edge->next;
        }
    }

    // �ִ� ��� ���
    printf("����\t�Ÿ�\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    free(dist);
}

int main() {
    int V = 5; // ������ ����
    Graph* graph = createGraph(V);

    // ���� �߰�
    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);

    int src = 0; // ���� ����
    BellmanFord(graph, src);

    return 0;
}