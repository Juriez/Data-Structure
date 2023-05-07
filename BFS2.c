#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int mat[26][26],rear=-1,front=-1,queue[26],visit[26]={0},n,i,j,count=0,colour[26],prev[26],dis[26];
#define WHITE 0
#define GRAY 1
#define BLACK 2
int main()
{
    int vtx;
    //freopen("bfs.txt","r",stdin);
    printf("Enter number of vertex \n");
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
    BFS(mat,vtx,n);
    return 0;

}
void BFS(int mat[26][26],int vtx,int n)
{
    if(count==0)
    {
       for(i=0;i<n;i++)
       {
           colour[i]=WHITE;
           prev[i]=-1;
           dis[i]=INT_MAX;
       }
    }
    colour[vtx]=GRAY;
    prev[vtx]=-1;
    dis[vtx]=0;
    insert_queue(vtx);
    while(queue_size()!=0)
    {
        int u=delete_queue();
        for(i=0;i<n;i++)
        {
            if(mat[u][i]==1 && colour[i]==WHITE)
            {
                colour[i]=GRAY;
                prev[i]=u;
                dis[i]=dis[u]+1;
                insert_queue(i);

            }
        }
        colour[u]=BLACK;
    }
    count++;
}
void insert_queue(int x)
{
    if(rear==-1)
    {
        queue[0]=x;
        rear++;
        front++;
    }
    else
    {
        front++;
        queue[front]=x;
    }
}
int queue_size()
{
    if(rear>front)
        return 0;
    else
        return 1;
}
int delete_queue()
{
    i=rear;
    rear++;
    return queue[i];
}


