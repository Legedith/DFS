// Implement depth first search in C
#include <stdio.h>
#include <stdlib.h>

void DFS(int graph[][10], int n, int s)
{
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[s] = 1;
    printf("%d ", s);
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;
    stack[++top] = s;
    while (top != -1)
    {
        int u = stack[top--];
        for (int i = 0; i < n; i++)
        {
            if (graph[u][i] && !visited[i])
            {
                visited[i] = 1;
                printf("%d ", i);
                stack[++top] = i;
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
    int graph[n][n];
    // Intitalize the graph to zeros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
            
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

    // print the graph
    printf("\nThe graph is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    DFS(graph, n, s);
    return 0;
}
