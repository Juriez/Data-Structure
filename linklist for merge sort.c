#include<stdio.h>
#include<stdlib.h>
    struct node{
    int data;
    struct node* next;
    };
    struct node* merge(struct node* a,struct node* b);
    void frontbacksplit(struct node* source,struct node** frontref,struct node** backref);
    /*sort the link list by changing next pointers not data*/
    void mergesort(struct node** headref)
    {
        struct node* head =*headref;
        struct node* a;
        struct node* b;
        if(head==NULL || head ->next==NULL)
        {
            return;
        }
        //split head into a & b sublist
        frontbacksplit(head,&a,&b);
        //recursively sort the sublist
        mergesort(&a);
        mergesort(&b);
        /*answer=merge the two sorted list together*/
        *headref =merge(a,b);
    }
    struct node* merge(struct node* a,struct node* b)
    {
        struct node* result=NULL;
        //base cases
        if(a==NULL)
        {
            return b;
        }
        else if(b==NULL)
            return a;
        //pick either a or b & recur
        if(a->data <= b->data)
        {
            result=a;
            result->next=merge(a->next,b);
        }
        else
            {
            result=b;
            result->next=merge(a,b->next);
        }
        return (result);
    }
   void frontbacksplit(struct node* source,struct node** frontref,struct node** backref)
   {
       struct node* fast;
       struct node* slow;
       slow=source;
       fast=source->next;
       /* advance fast two nodes & advance slow one node*/
       while(fast!=NULL)
       {
           fast=fast->next;
           if(fast!=NULL)
           {
               slow=slow->next;
               fast=fast->next;
           }
       }
       /* slow is before the midpoint in the list,so split it in two at that point*/
       *frontref=source;
       *backref=slow->next;
       slow->next=NULL;
   }
   //function to print nodes in a list
   void printlist(struct node* node2)
   {
       while(node2!=NULL)
       {
           printf("%d ",node2->data);
           node2=node2->next;
       }
   }
   //function to insert a node at the beginning of the list
   void push(struct node** head_ref,int newdata)
   {
       struct node* newnode=(struct node*)malloc(sizeof(struct node));
       newnode->data=newdata;
       newnode->next=(*head_ref);
       (*head_ref)=newnode;//move the head to point to the newnode

   }
   int main()
   {
       //struct node* res=NULL;
       struct node* a=NULL;
       push(&a,15);
       push(&a,10);
       push(&a,34);
       push(&a,5);
       push(&a,104);
       push(&a,67);
       printf("Before sort link list is :\n");
       printlist(a);
       mergesort(&a);
       printf("\nSorted link list is\n");
       printlist(a);
       getchar();
       return 0;
   }
