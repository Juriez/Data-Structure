#include<stdio.h>
#include<stdlib.h>
    struct node {
       int data;
       struct node *next;
    };
//add new node at the end of the link list
void insert(struct node **head,int value)
{
    struct node *node2=(struct node *)malloc(sizeof(struct node));
    if(node2!=NULL)
    {
        node2->data=value;
        node2->next=NULL;
        if(*head==NULL)
            *head=node2;
        else
        {
            struct node *temp=*head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=node2;//adding node at last position
        }
    }
    else
        printf("Memory overflow\n");
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("Ëmpty linked list");
        return ;
    }
    struct node *temp=head;
    printf("\nLinked list :");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
}
struct node *lastnode(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}
struct node *partition(struct node *first,struct node *last)
{
    struct node *pivot=first;
    struct node *front=first;
    int temp=0;
    while(front!=NULL && front!=last)
    {
        if(front->data < last->data)
        {
            pivot=first;
            temp=first->data;
            first->data=front->data;
            front->data=temp;
            first=first->next;
        }
        front=front->next;
    }
    temp=first->data;
    first->data=last->data;
    last->data=temp;
    return pivot;
}
void quicksort(struct node *first, struct node *last)
{
    if(first==last)
    {
        return ;
    }
    struct node *pivot=partition(first,last);
    if(pivot!=NULL && pivot->next!=NULL)
    {
        quicksort(pivot->next,last);
    }
    if(pivot!=NULL && first!=pivot)
    {
        quicksort(first,pivot);
    }
}
int main()
{
    struct node *head=NULL;
    insert(&head,42);
    insert(&head,34);
    insert(&head,109);
    insert(&head,67);
    insert(&head,45);
    insert(&head,19);
    printf("\nBefore sort :");
    display(head);
    quicksort(head,lastnode(head));
    printf("\nAfter sort :");
    display(head);
    return 0;

}
