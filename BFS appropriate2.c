#include<stdio.h>
#include<stdlib.h>
#define max_size 6

int G[max_size][max_size];
char C[max_size];
int Lev[max_size];
int par[max_size];



int main()
{
    int edgeCount;
    scanf("%d",&edgeCount);

    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        scanf("%d%d",&u,&v);

        G[u][v] = 1;
    }

    int sourceNode=3;
    //scanf("%d",&sourceNode);

    for (int i = 0; i < max_size; ++i) {
        C[i] = 'w';
        Lev[i] =-1;
        par[i] = -1;
    }

    int Queue[max_size];
    int startP, endP;
    startP = 0;
    endP = 0;
    Queue[endP] = sourceNode;
    endP = endP + 1;
    C[sourceNode] = 'g';
    Lev[sourceNode] = 0;
    par[sourceNode] = -1;


    while (endP - startP > 0) {
        int u = Queue[startP];
        for (int i = 0; i < max_size; ++i) {
            int v = i;

            if (G[u][v] == 1 && C[v] == 'w') {
                Queue[endP] = v;
                endP = endP + 1;
                C[v] = 'g';
                Lev[v] = Lev[u] + 1;
                par[v] = u;
            }
        }
        startP = startP + 1;
        C[u] = 'b';
    }

    for (int i = 0; i < max_size; ++i) {
        printf("Level[%d]=%d\n",i,Lev[i]);

        printf("Parent[%d]=%d\n",i,par[i]);

        printf("Color[%d]=%c\n",i,C[i]);
        if(par[i]==3)
            printf("YES she can visited from INDIA to that country\n");
        else
            printf("No she can not visit\n");

        printf("\n");
    }

    return 0;
}

/*
6
5 2
5 1
5 3
1 3
1 4
4 2

*/


