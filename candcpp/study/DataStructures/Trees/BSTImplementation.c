#include<stdio.h>
#include<stdlib.h>
 
/******************************************************
Binary Search Tree:
The nodes with lesser value than parent node are placed at left side
The nodes with greater value than parent node are placed at right side

validations are necessary at every point since these functions are recursive 

NOTE:
We can use all the Traversals in BST similar to Binary Tree
Among All traversals, Inorder traversal in BST will give the o/p in Ascending order
******************************************************/

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

#if 1 //Follow this method,No need of below code
struct node* insert(struct node* root, int newdata)
{
	if(root == NULL) //V.V.Imp, data validation
	{
#if 1 //same as Binary Tree
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = newdata;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
#endif
	}

	if (newdata < root->data) //data validation and then insertion accordingly
	{
		root->left  = insert(root->left, newdata); //V.V.Imp
	}
	else if (newdata > root->data) //data validation and then insertion accordingly
	{
		root->right = insert(root->right, newdata); //V.V.Imp   
	}
	return root; //V.V.Imp   
}
#endif

#if 0
struct node* createNode(value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
  
  
struct node* insert(struct node* root, int data)
{
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
    return root;
}
#endif

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
    struct node *root = NULL; //Imp,Since we are passing root as argument to insert func,make root as NULL
    root = insert(root, 8); //This step is V.V.Imp
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    Preorder(root);
    printf("\n");

    Inorder(root); //Gives o/p in Ascending order only in BST not in BT
    printf("\n");

    Postorder(root);
    printf("\n");
}
