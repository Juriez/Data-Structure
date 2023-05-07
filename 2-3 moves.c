#include<stdio.h>
int main()

{
    int i,t,a[10000];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&a[i]);

    }
    for(int j=0;j<t;j++)
    {
        if(a[j]==1)
        {
            printf("%d\n",2);
        }
        else if(a[j]==2)
        {
            printf("%d\n",1);
        }
        else if(a[j]%3==0)
        {
            printf("%d\n",a[j]/3);
        }
        else if(a[j]%3!=0)
        {
            printf("%d\n",(a[j]/3)+1);
        }
    }
}
