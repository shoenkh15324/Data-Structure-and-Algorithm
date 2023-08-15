#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define NOT_CONNECTED -1

int graph[MAX_VERTICES][MAX_VERTICES];
int vertices;

void initialize_graph() {
    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = NOT_CONNECTED;
        }
    }
}

void add_edge(int start, int end, int weight) {
    graph[start][end] = weight;
    graph[end][start] = weight;
}

void print_graph() {
    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (graph[i][j] == NOT_CONNECTED) {
                printf("%7s", "N/A");
            }
            else {
                printf("%7d", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j, number_of_edges, start, end, weight;

    printf("Enter the number of vertices: ");
    scanf_s("%d", &vertices);
    initialize_graph();

    printf("Enter the number of edges: ");
    scanf_s("%d", &number_of_edges);
    for (i = 0; i < number_of_edges; i++) {
        printf("Enter edge %d (start end weight): ", i + 1);
        scanf_s("%d%d%d", &start, &end, &weight);
        add_edge(start, end, weight);
    }

    printf("Graph:\n");
    print_graph();

    return 0;
}