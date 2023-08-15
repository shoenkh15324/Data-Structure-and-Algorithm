#define _CRT_SECURE_NO_WARNINGS

//น้มุ 1260น๘

#include <stdio.h>
#include <stdlib.h>

int N;
int graph[1001][1001] = { 0, }, visit[1001] = { 0, }, queue[1001];

void BFS(int V)
{
	int front = 0, rear = 1, pop;
	visit[V] = 1;
	printf("%d", V);
	queue[0] = V;
	while (front < rear)
	{
		pop = queue[front++];
		for (int i = 1; i <= N; i++)
		{
			if (graph[pop][i] && !visit[i])
			{
				visit[i] = 1;
				printf("%d ", i);
				queue[rear++] = i;
			}
		}
	}
}

int main()
{
	int M, V, x, y;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	BFS(V);

	return 0;
}