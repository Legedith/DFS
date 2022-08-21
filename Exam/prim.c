// Implement prims's in c without using limits
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int V;

void main()
{
    int[V][V] graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // int graph[V][V];
    // printf("Enter the adjacency matrix: \n");
    // for (int i = 0; i < V; i++)
    //     for (int j = 0; j < V; j++)
    //         scanf("%d", &graph[i][j]);
    
    // // Print the adjacency matrix
    // printf("The adjacency matrix is: \n");
    // for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++)
    //         printf("%d ", graph[i][j]);
    //     printf("\n");
    // }
}