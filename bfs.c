// Implement Breadth First Search in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

void bfs(int **graph, int n, int s)
{
    int *visited = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[s] = 1;
    printf("%d ", s);
    int *queue = (int *)malloc(sizeof(int) * n);
    int front = -1, rear = -1;
    rear++;
    queue[rear] = s;
    while (front != rear)
    {
        front++;
        int u = queue[front];
        for (int i = 0; i < n; i++)
        {
            if (graph[u][i] && !visited[i])
            {
                visited[i] = 1;
                printf("%d ", i);
                rear++;
                queue[rear] = i;
            }
        }
    }

}

int main()
{
    int n, m, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    int **graph = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    printf("Enter edges: ");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    printf("Enter source vertex: ");
    scanf("%d", &s);
    bfs(graph, n, s);
    return 0;
}