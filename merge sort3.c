#include<stdio.h>
#include<limits.h>
void mergesort(int arr[],int left,int right);
void merge(int arr[],int mid,int left,int right);
int main()

{
    int n,i,p,r;
    printf("How many number want to be sorted?\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter first & last index.\n");
    scanf("%d %d",&p,&r);
    mergesort(a,p,r);
    for(i=0;i<n;i++)
    {
       printf("%d ",a[i]);
    }
}
void mergesort(int arr[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void merge(int arr[],int mid,int left,int right)
{
    int n1,n2,i;
    n1=mid-left+1;
    n2=right-mid;
    int b[n1+1],c[n2+1];

    for(i=0;i<n1;i++)
    {
        b[i]=arr[left+i];
    }
    for(i=0;i<n2;i++)
    {
        c[i]=arr[mid+1+i];
    }
    b[n1]=INT_MAX;
    c[n2]=INT_MAX;
    int k,j=0;
    i=0;
    for(k=left;k<right+1;k++)
    {
        if(c[j]<b[i])
        {
            arr[k]=c[j];
            j++;
        }
        else
        {
            arr[k]=b[i];
            i++;
        }
    }


}
