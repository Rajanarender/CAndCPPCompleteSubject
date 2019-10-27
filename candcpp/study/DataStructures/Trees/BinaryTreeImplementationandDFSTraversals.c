#include<stdio.h>
#include<stdlib.h> //for malloc

/******************************************************
Binary Tree:
Representation of data in tree structure with each parent node having 2 childs(left,right)

Binary Search Tree:
This is a kind of Binary Tree with conditions as
=> left child node value lesser than its parent node
=> right child node value greater than its parent node


DFS[Depth First Search] - Preorder,Inorder,Postorder comes under it
Time Complexity of this 3 traversals is O(n)

BFS or Level Order Traversal:
Time Complexity of this traversal is O(n)

validations are necessary at every point since these functions are recursive 
******************************************************/

struct node
{
	int data;
	struct node *left;
	struct node *right;
};


struct node* insert(int newdata)
{

	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void Preorder(struct node *root)
{
	if(root == NULL)
		return;
	printf("%d ->",root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(struct node *root)
{
	if(root == NULL)
		return;
	Inorder(root->left);
	printf("%d ->",root->data);
	Inorder(root->right);
}

void Postorder(struct node *root)
{
	if(root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ->",root->data);
}

int main()
{
	struct node *root = insert(9);
	root->left = insert(4);
	root->right = insert(6);
	root->left->left = insert(8);
	root->left->right = insert(7);
	root->right->left = insert(2);
        root->right->right = insert(10);

        Preorder(root);
        printf("\n");

        Inorder(root);
        printf("\n");

        Postorder(root);
        printf("\n");
}
