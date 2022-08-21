#include <stdio.h>

typedef struct edge {
    int u, v, w;
} edge;

typedef struct list_of_edges {

  edge data[5];
  int n;

} list_of_edges;

list_of_edges List;

int Graph[5][5], n;

list_of_edges spanlist;


void kruskalAlgo() {
    int belongs[5], i, j, cno1, cno2;
    List.n = 0;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {

                    List.data[List.n].u = i;
                    List.data[List.n].v = j;
                    List.data[List.n].w = Graph[i][j];
                    List.n++;

            }
        }
    }

    sort();

    for (i = 0; i < n; i++)
        belongs[i] = i;
        spanlist.n = 0;
        
        for (i = 0; i < List.n; i++) {

            cno1 = find(belongs, List.data[i].u);
            cno2 = find(belongs, List.data[i].v);

            if (cno1 != cno2) {
                spanlist.data[spanlist.n] = List.data[i];
                spanlist.n = spanlist.n + 1;
                applyUnion(belongs, cno1, cno2);
            }
        }
}

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
        belongs[i] = c1;
}
void sort() {
  int i, j;
  edge temp;
  for (i = 1; i < List.n; i++)
    for (j = 0; j < List.n - 1; j++)
      if (List.data[j].w > List.data[j + 1].w) {
        temp = List.data[j];
        List.data[j] = List.data[j + 1];
        List.data[j + 1] = temp;
      }
}
void Print_mst() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nMinimum cost: %d", cost);
}

int main() {
    int i, j, total_cost;
    n = 5;
    Graph[0][1] = 2;
    Graph[1][0] = 2;

    Graph[0][3] = 6;
    Graph[3][0] = 6;

    Graph[1][2] = 3;
    Graph[2][1] = 3;

    Graph[1][3] = 8;
    Graph[3][1] = 8;

    Graph[1][4] = 5;
    Graph[4][1] = 5;

    Graph[2][4] = 7;
    Graph[4][2] = 7;

    Graph[3][4] = 9;
    Graph[4][3] = 9;
    kruskalAlgo();
    Print_mst();
}