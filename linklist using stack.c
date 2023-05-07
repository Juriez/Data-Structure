#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int size=0;
struct node *head;

 print(struct node *head)
{
   //struct node* cur_node=head;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
push(struct node *newnode)
{
    struct node* cur_node=head;
    for(int i=0;i<size;i++)
    {
        cur_node=cur_node->next;
    }
    size++;
    cur_node->next=newnode;
    newnode->next=NULL;

}
pop()
{
    struct node* cur_node=head;
    for(int i=0;i<size-1;i++)
    {
        cur_node=cur_node->next;
    }
    size--;
     cur_node->next=cur_node->next->next;

}
int main()

{
    //struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=10;
    struct node *newone=(struct node *)malloc(sizeof(struct node));
    newone->data=5;
    struct node *newtwo=(struct node *)malloc(sizeof(struct node));
    newtwo->data=15;

    head->next=newone;
    newone->next =newtwo;
    newtwo->next=NULL;

    print(head);
    /* now we insert a new value in list*/
    int a;
    struct node *inserting=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter new number.\n");
    printf("\n");
    scanf("%d",&a);
    inserting->data=a;
    push(inserting);
    print(head);
    /*now we delete a number from the list*/
    printf("\n");
   pop();
    print(head);

}

