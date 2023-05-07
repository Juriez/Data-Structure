#include<stdio.h>
#define CAPACITY 7
int stack[CAPACITY];
int rear=-1;
int front=1;
void push(int x){
    if(rear<CAPACITY-1)
    {
        rear=rear+1;
        stack[rear]=x;
        printf("Successfully added the item: %d\n",x);
    }
    else
        printf("Exception!! No spaces.\n");
}
int delete(int front){
    if(front==CAPACITY+1)
    {
       // int a=stack[rear];
        //rear=rear-1;
        //return a;
        printf("QUEUE empty :");

    }
    else
    {
        int x= stack[front];
        front=front+1;
    }
    return;
}
int main()
{
    //peek();//as now stack is empty,so it will print the else output.
    push(34);
    push(40);
    push(60);
    push(70);
    push(90);
    push(100);
    for(int i=CAPACITY-1;i>0;i++)
    {
         printf("Pop item: %d\n",delete(i));

    }


    push(120);//after call pop(),one index will be free,& restore 120 & other value.
    //printf("Peek item: %d\n",peek());
    return 0;
}
