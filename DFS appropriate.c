#include <stdio.h>
#include<stdlib.h>
#define max_size 7


int G[max_size][max_size];
char C[max_size];
int par[max_size];

void DFS(int node) {

    C[node] = 'g';
    for (int i = 0; i < max_size; ++i) {
        int adj = i;
        if (G[node][adj] == 1 && C[adj] == 'w') {
            par[adj] = node;
            DFS(adj);
        }
    }
    C[node] = 'b';
}

int main()
{
    int edgeCount;
    scanf("%d",&edgeCount);
    printf("Enter edges :");
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;

       scanf("%d%d",&u,&v);

        G[u][v] = 1;
    }

    for (int i = 0; i < max_size; ++i) {
        C[i] = 'w';
        par[i] = -1;
    }

    int sourceNode;

    scanf("%d",&sourceNode);

    DFS(sourceNode);
    par[sourceNode] = -1;


    for (int i = 0; i < max_size; ++i) {

        printf("Parent[%d]=%d\n",i,par[i]);
         printf("Color[%d]=%c\n",i,C[i]);

        printf("\n");
    }

    return 0;
}

/*
8
1 6
1 4
4 3
3 5
3 2
2 1
5 2
3 1
1
*/

