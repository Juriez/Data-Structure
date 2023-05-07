
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* left;
	struct node* right;
	int data;
};
struct stack
{
	struct node* data;
	struct stack* next;
};

void push(struct stack** top,struct node* n);
struct node* pop(struct stack** top);
int isEmpty(struct stack* top);

int tree_traversal(struct node* root)
{
	struct node* temp = root;
	struct stack* s_temp = NULL;
	int temp2 = 1;
	while(temp2) //Loop run until temp is null and stack is empty
	{
		if(temp){
			push(&s_temp,temp);
			temp = temp->left;
		}
		else{
			if(!isEmpty(s_temp)){
				temp = pop(&s_temp);
				printf("%d ",temp->data);
				temp = temp->right;
			}
			else
				temp2 = 0;
		}
	 }
}
void push(struct stack** top,struct node* n)
{
	struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
	newnode->data = n;
	newnode->next = (*top);
	(*top) = newnode;
}
int isEmpty(struct stack* top)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
struct node* pop(struct stack** top_n)
{
	struct node* item;
	struct stack* top;
	top = *top_n;
	item = top->data;
	*top_n = top->next;
	free(top);
	return item;
}
struct node* newnode(int data)
{
	struct node* new_n = (struct node*)malloc(sizeof(struct node));
	new_n->data = data;
	new_n->left = NULL;
	new_n->right = NULL;
	return (new_n);
}

int main()
{
	struct node* root;
	root = newnode(8);
	root->left = newnode(5);
	root->right = newnode(4);
	root->left->left = newnode(7);
	root->left->right = newnode(6);
	root->right->left=newnode(9);
	root->right->right=newnode(10);
	tree_traversal(root);
	return 0;
}
