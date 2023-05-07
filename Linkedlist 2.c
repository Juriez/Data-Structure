#include<stdio.h>
#include<stdlib.h>
struct hudai{
    int data;
    struct hudai *next;
    };
    int main()

    {
        struct hudai *x=NULL;
        struct hudai *y=NULL;
        struct hudai *z=NULL;
        x=(struct hudai *)malloc(sizeof(struct hudai));
        y=(struct hudai *)malloc(sizeof(struct hudai));
        z=(struct hudai *)malloc(sizeof(struct hudai));


        x->data=90;
        y->data=43;
        z->data=56;
        x->next=y;
        y->next=z;
        z->next=NULL;

        while(x!=NULL)
        {
           if(x->data > y->data && x->data > z->data)
            printf("%d-->",x->data);
            x=x->next;
        }
        return 0;
    }
