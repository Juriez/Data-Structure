#include<stdio.h>
#include<stdlib.h>
int mat[26][26],rear=-1,front=0,queue[26],visit[26]={0},n,i,j;
int main()
{
    int vtx;
    freopen("bfs.txt","r",stdin);
    printf("Enter the value of number of vertex :\n");
    scanf("%d",&n);

    printf("Enter the adjacancy matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    printf("Enter the preliminary vertex :\n");
    scanf("%d",&vtx);

    BFS(vtx);

    printf("Explored nodes are :\n");

    for(i=0;i<n;i++)
    {
        if(visit[i])
        {
            // printf("%d   ",i);
            if(i==0)
                printf("A");
            else if(i==1)
            printf("  B");
            else if(i==2)
            printf("  C");
            else if(i==3)
            printf("  D");
            else if(i==4)
            printf("  E");
            else if(i==5)
            printf("  F");
            else if(i==6)
            printf("  G");
            else if(i==7)
            printf("  H");
            else if(i==8)
            printf("  I");

        }

        else
        {
            printf("\nNot all nodes are explored!! \n");
            break;
        }
    }

}

void BFS(int x)
{
    for(i=0;i<n;i++)
    {
        if(mat[x][i]==1 && visit[i]==0)
        {
            rear=rear+1;
            queue[rear]=i;
        }
    }
        if(front<=rear)
        {
            visit[queue[front]]=1;
            BFS(queue[front++]);
        }

}
