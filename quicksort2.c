#include<stdio.h>
int partition(int A[],int l,int h);
void quicksort(int A[],int l,int h);
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    int l=0;int h=n-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,l,h);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}
void quicksort(int A[],int l,int h)
{
    if(l<h)
    {
        int j=partition(A,l,h);
        quicksort(A,l,j-1);
        quicksort(A,j+1,h);
    }
}
int partition(int A[],int l,int h)
{
   int pivot=A[l];
   int i=l,j=h,temp=0;
   while(i<j)
   {
       if(A[i]<=pivot)
       {
           i++;
       }
       if(A[j]>pivot)
       {
           j--;
       }
       temp=A[i];
       A[i]=A[j];
       A[j]=temp;
       temp=0;
   }
   temp=A[l];
   A[l]=A[j];
   A[j]=temp;
   return j;
}

