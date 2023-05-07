#include<stdio.h>
#include<stdlib.h>
#include<LIMITS.h>
int d[2000],f[2000],arr[200][200],pre[2000],v,time,vertex[200];
char colour[2000];
void DFS(int source)
{
  int i,j;
  int u=source;
   for(i=1;i<=v;i++)
    {
        colour[i]='w';
        pre[i]=-1;
        d[i]=-1;
    }
    time=0;
    IS_Visited(u);
}

void IS_Visited(int u)
{
    int i;
    colour[u]='g';
    time=time+1;
    d[u]=time;
    for(i=1;i<=v;i++)
       {
              if(arr[u][i]==1 && colour[i]=='w')
               {
                   pre[i]=u;
                   IS_Visited(i);
               }
           }
       colour[u]='b';
       time=time+1;
       f[u]=time;
}
void topologicalSort()
{
   int i,j;
   int temp;

   for(i=1;i<=v;i++)
   {
       for(j=i+1;j<=v;j++)
       {
           if(f[vertex[i]]<f[vertex[j]])
           {
               temp=vertex[j];
               vertex[j]=vertex[i];
               vertex[i]=temp;
           }
       }
   }
   printf("Topological Sort:\n");
   for(i=1;i<=v;i++)
   {
       printf("%d ",vertex[i]);
   }
   printf("\n");
}
void print()
{
    int i;
   for(i=1;i<=v;i++)
   {
       printf("%c ",colour[i]);
   }
    printf("\n");
   for(i=1;i<=v;i++)
   {
       printf("%d ",d[i]);
   }
    printf("\n");
   for(i=1;i<=v;i++)
   {
       printf("%d ",pre[i]);
   }
    printf("\n");
    for(i=1;i<=v;i++)
   {
       printf("%d ",f[i]);
   }
    printf("\n");
}
int main()
{
    int x,y,u,n,s,i,j,edge;
    freopen("Toplogicalsort.txt","r",stdin);
    printf("Enter the number of vertices:\n");
    scanf("%d",&v);
    for(i=1;i<=v;i++)
    {
        scanf("%d",&vertex[i]);
    }

    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            arr[i][j]=0;
        }
    }
    printf("Enter the number of edges:\n");
    scanf("%d",&edge);
    while(edge--)
    {
        printf("Enter the path:\n");
        scanf("%d",&x);
        scanf("%d",&y);
        arr[x][y]=1;
    }

   for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
     printf("Enter source:\n");
    scanf("%d",&s);
    DFS(s);
     for(i=1;i<=v;i++)
       {
         if(colour[i]=='w') IS_Visited(i);
       }
       topologicalSort();
    print();
  return 0;
}

/*
7
1 2 3 4 5 6 7
8
1 2
1 3
2 3
2 5
3 4
4 5
5 6
6 7
3
*/


