#include<stdio.h>
#include<stdlib.h>
struct node{

    int key;
    struct node *left,*right;

};
struct node *newnode(int x){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);//traverse left
        printf("%d ",root->key) ;//traverse root
        inorder(root->right); //traverse right

    }
}

struct node *insert(struct node *node,int key)
{
        if(node==NULL)
            return newnode(key);
        if(key< node->key)
            node->left= insert(node->left, key);
        else
            node->right= insert(node->right,key);
        return node;
}

struct node *minimumvalue(struct node *node)
{
        struct node *z=node;
        while(z && z->left!=NULL)
        {
            z= z->left;
        }
       printf("%d\n",z->key);
}

struct node *maximumvalue(struct node *node)
{
        struct node *w= node;
        while(w && w->right!=NULL)
        {
            w=w->right;
        }
        printf("%d\n",w->key);
}

struct node *deleting(struct node *root,int key)
{
        if(root==NULL)
            return root;
        if(key< root->key)
            root->left=deleting(root->left,key);
            else if(key > root->key)
            root->right=deleting(root->right,key);
        else
        {
            if(root->left==NULL)
                {struct node *temp=root->right;
            free(root);
            return temp;}
            else if(root->right==NULL)
            {
                struct node *temp= root->left;
                free(root);
                return temp;
            }
            struct node *temp=minimumvalue(root->right);
            root->key=temp->key;
            root->right= deleting(root->right,temp->key);

        }
        return root;
}
int main()
{
    struct node *root=NULL;
    root= insert(root,23);
    root=insert(root,12);
    root=insert(root,3);
    root= insert(root,14);
    root=insert(root,6);
    root=insert(root,9);
    root=insert(root,16);
    root=insert(root,15);

    printf("Inorder Tree :");
    inorder(root);
    printf("\n");
    printf("Minimum node :");
    minimumvalue(root);
    printf("Maximum node :");
    maximumvalue(root);
    printf("After deleting :");
    deleting(root,9);
    printf("Inorder Tree :");
    inorder(root);


}
