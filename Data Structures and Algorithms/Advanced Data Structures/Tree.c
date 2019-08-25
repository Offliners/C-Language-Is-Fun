#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node n;

n* createNode(int value);
n* insertLeft(n *root,int value);
n* insertRight(n *root,int value);

int main()
{
	n *root = createNode(1);

	insertLeft(root,2);
	insertRight(root,3);
	printf("The elements of tree are %d %d %d",root->data,root->left->data,root->right->data);
	return 0;
}

n* createNode(int value)
{
	n *newNode = malloc(sizeof(n));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

n* insertLeft(n *root,int value)
{
	root->left = createNode(value);
	return root->left;
}

n* insertRight(n *root,int value)
{
	root->right = createNode(value);
	return root->right;
}
