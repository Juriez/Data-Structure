#include<stdio.h>
#include<stdlib.h>
char stack[30];

int top=-1;
void push(char x){
        top=top+1;
        stack[top]=x;
}
char pop()
{
    if(top>=0)
    {
        char a=stack[top];
        top=top-1;
        return a;
    }
    else
    return -1;
}
int priority(char x)
{
    if(x=='(')
        return 0;
    else if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='^')
        return 3;
}
int main()
{
    char ch[30];
    char *p,x;
    printf("Enter a expression.\n");
    scanf("%s",&ch);
    //p=ch;
    int i=0;
    while(ch[i]=NULL)
    {
        if(isalnum(ch[i]))
        {
            printf("%c",ch[i]);
        }
        else if(ch[i]=='(')
        {
            push(ch[i]);
        }
        else if(ch[i]==')')
        {
            while((x==pop())!='(')
            {
                printf("%c",x);


            }
            push(ch[i]);
        }
        else
        {
            while(priority(stack[top])>=priority(ch[i]))
                {printf("%c",pop());
            //push(ch[i]);}
            }
        }
         push(ch[i]);
       i++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
        break;
    }
}
