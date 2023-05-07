#include<stdio.h>
int main()

{
    int n,t,count=0;
    scanf("%d %d",&n,&t);
    int a[n-1];
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        if(i+1+a[i]==t)
        {
           count++;
        }

    }
    if(count>0)
        printf("YES");
    else
        printf("NO");



}
