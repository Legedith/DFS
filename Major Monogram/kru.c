// Kruskal's algo
#include<stdio.h>
 
struct edge
{
    int u,v,w;
}edge;
 
struct edgelist
{
    edge data[5];
    int n;
}edgelist;
 
edgelist elist;
 
int G[5][5];
int n = 5;
edgelist spanlist;

void kruskal()
{
    int belongs[5],i,j,cno1,cno2;
    elist.n=0;
    
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(G[i][j]!=0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }
 
    sort();
    for(i = 0; i < n; i++)
        belongs[i] = i;
        spanlist.n = 0;
        for(i = 0; i < elist.n; i++)
        {
            cno1 = find(belongs, elist.data[i].u);
            cno2 = find(belongs, elist.data[i].v);
            if(cno1!=cno2)
            {
                spanlist.data[spanlist.n]=elist.data[i];
                spanlist.n=spanlist.n+1;
                union1(belongs,cno1,cno2);
            }
        }
}
 
int find(int belongs[],int vertexno)
{
return(belongs[vertexno]);
}
 
void union1(int belongs[],int c1,int c2)
{
int i;
for(i=0;i<n;i++)
if(belongs[i]==c2)
belongs[i]=c1;
}
 
void sort()
{
int i,j;
edge temp;
for(i=1;i<elist.n;i++)
for(j=0;j<elist.n-1;j++)
if(elist.data[j].w>elist.data[j+1].w)
{
temp=elist.data[j];
elist.data[j]=elist.data[j+1];
elist.data[j+1]=temp;
}
}
 
void print()
{
    int i,cost=0;
    for(i=0;i<spanlist.n;i++)
    {
        printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
        cost=cost+spanlist.data[i].w;
    }
    
    printf("\n\nCost of the spanning tree=%d",cost);
}
void main()
{
    int i,j,total_cost;
    // Initialize a 5*5 adjacency matrix for weighted graph G
    int[5][5] G = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    kruskal();
    print();
}