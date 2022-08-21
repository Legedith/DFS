// Implement Prims's algorithm for finding a minimum spanning tree
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int V;

int minKey(int key[], bool mstSet[])
{
    int min = 99;
    int min_index; 
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    return min_index;
}
 
int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    // key is the distance from the source to the vertex
    // parent is the parent of the vertex
    // mstSet is the set of vertices in the MST
 
    for (int i = 0; i < V; i++)
    {
        key[i] = 99;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1; 
 
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // print the constructed MST
    printMST(parent, graph);
}
 
int main()
{
    // Get the number of vertices in the graph from user
    // printf("Enter the number of vertices: ");
    // scanf("%d", &V);

    V = 5;
    int graph[5][5] =   { 
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0} };



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

    primMST(graph);
 
    return 0;
}