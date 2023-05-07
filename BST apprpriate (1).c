#include<stdio.h>
#include<stdlib.h>
struct node{

int key;
struct node *left,*right;
struct node *parent;
struct node *root;
};


    struct node *newnode(int x){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->key=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    void inorder(struct node *root){
        if(root!=NULL)
        {
            inorder(root->left);
            printf("%d ",root->key);
            inorder(root->right);
        }

    }
    struct node *TreeSearch(struct node *x, int k)
    {
            if(x==NULL || k==x->key)
                return x;
            if(k<x->key)
                return TreeSearch(x->left,k);
            else
                return TreeSearch(x->right,k);

    }

struct node *insert(struct node *node,int key)
    {

        if(node==NULL)
            return newnode(key);
        else
        {
            struct node *temp;
        if(key<= node->key)
            {

                temp=insert(node->left,key);
                node->left=temp;
                temp->parent=node;
            }
        else
            {
                temp=insert(node->right,key);
                node->right=temp;
                temp->parent=node;

            }
        return node;
        }
    }
struct node *minimumvalue(struct node *m)
    {

        while(m->left!=NULL)
            m=m->left;
       printf("%d \n",m->key);

    }
struct node *maximumvalue(struct node *m)
    {

        while(m->right!=NULL)
            m=m->right;
       printf("%d \n",m->key);

    }
struct node *successor(struct node *x)
{
        if(x->right!=NULL)
            return minimumvalue(x->right);
        struct node *y=NULL;
        y=x->parent;
        while(y!=NULL && x==y->right)
        {
            x=y;
            y=y->parent;
        }
        return y;


}
struct node *deleting(struct node *T,struct node *z)
{
       struct node *y =NULL;
        struct node *x=NULL;
       // struct node *root=NULL;
        if(z->left== NULL || z->right==NULL)
          y=z;
        else
            y=successor(z);
        if(y->left !=NULL)
           x=y->left;
        else
            x=y->right;
        if(x!=NULL)
            x->parent=y->parent;
        if(y->parent==NULL)
            T->root=x;
        else if(y==y->parent->left)
            y->parent->left=x;
        else
            y->parent->right=x;
        if(y!=z)
            z->key=y->key;
        return y;


}
int main()
{
   struct node *root=NULL;

   root=insert(root,10);
   root=insert(root,7);
   root=insert(root, 12);
   root=insert(root,5);
   root=insert(root, 8);
   root=insert(root,13);
   root=insert(root, 9);
   root=insert(root,6);

   printf("Inorder Tree :");
   inorder(root);
   printf("\nMinimum Node :");
   minimumvalue(root);
   printf("Maximum Node :");
   maximumvalue(root);

   struct node *x= NULL;
   x = TreeSearch(root, 12);
   printf("\nSearched value is %d\n", x->key);
   struct node *xx= NULL;
   xx = successor(x);

   printf("Search the value that you want to delete.\n");
   x = TreeSearch(root, 9);
   printf("After deleting 9:");
   deleting(root,x);
   inorder(root);
   printf("\n");

}

