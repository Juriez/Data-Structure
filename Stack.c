#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY];
int top=-1;
void push(int x){
    if(top<CAPACITY-1)
    {
        top=top+1;
        stack[top]=x;
        printf("Successfully added the item: %d\n",x);
    }
    else
        printf("Exception!! No spaces.\n");
}
int pop(){
    if(top>=0)
    {
        int a=stack[top];
        top=top-1;
        return a;
    }
    else
    {
        printf("Free pop,empty stack\n");
        return -1;
    }
}
int peek(){
    if(top>=0)
    {
        return stack[top];
    }
    else
    {
        printf("Free peek,empty stack\n");
        return -1;
    }
}
int main()
{
    peek();//as now stack is empty,so it will print the else output.
    push(34);
    push(40);
    push(60);
    push(70);
    push(90);
    push(100);
    for(int i=0;i<CAPACITY;i++)
    {
         printf("Pop item: %d\n",pop());

    }


    push(120);//after call pop(),one index will be free,& restore 120 & other value.
    printf("Peek item: %d\n",peek());
    return 0;
}

