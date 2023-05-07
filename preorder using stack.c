#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    };
struct node *newnode(int data){
    struct node* node2= (struct node*)malloc(sizeof(struct node));
    node2->data=data;
    node2->left=NULL;
    node2->right=NULL;
    return(node2);
}
void preorder(struct node* root)
{
    struct node* stack[35];
    struct node* ptr;
    int top=1;
    stack[1]=NULL;
    ptr=root;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        if(ptr->right!=NULL)
        {
            top=top+1;
        stack[top]=ptr->right;
        }
        if(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        else
        {
            ptr=stack[top];
            top=top-1;
        }
    }
}
int main()
{
    struct node* root=newnode(15);
    root->left=newnode(8);
    root->right=newnode(6);
    root->left->left=newnode(9);
    root->left->right=newnode(18);
    root->right->left=newnode(23);
    root->right->right=newnode(24);
    preorder(root);
}
