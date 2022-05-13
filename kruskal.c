// Implement Kruskal's in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Define the number of vertices in the graph
#define V 4


// A utility function to find the subset of an element i
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void union1(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

    parent[xset] = yset;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(int graph[V][V], int V, int parent[], int key[])
{
    // Sort all the edges in non-decreasing order of their
    // weight.  If we are not allowed to change the given graph,
    // we can create a copy of graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            key[i] = graph[i][j];

    // Sort all the edges in non-decreasing order of their
    // weight
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            for (int k = 0; k < V; k++)
                if (key[i] > key[j])
                {
                    int temp = key[i];
                    key[i] = key[j];
                    key[j] = temp;

                    temp = graph[i][j];
                    graph[i][j] = graph[j][i];
                    graph[j][i] = temp;
                }
    // Initialize parent
    for (int i = 0; i < V; i++)
        parent[i] = -1;
        
                

