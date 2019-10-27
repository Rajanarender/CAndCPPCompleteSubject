#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

struct node *Q[100];
int front = -1;
int rear = -1;

void enqueue(struct node *root)
{	
	Q[++rear] = root;
}

struct node* dequeue()
{
	return Q[++front];
}

void levelorder(struct node *root)
{
	enqueue(root);

	struct node *q;
	while(rear!=front) //V.V.Imp step,preorder traversal
	{
		q = dequeue();		
		printf("%d\t",q->data);
		if(q->left)
			enqueue(q->left);
		if(q->right)
			enqueue(q->right);		
	}
}

struct node* insert(struct node* root, int newdata)
{
	if(root == NULL) //V.V.Imp, data validation
	{
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = newdata;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
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

int main()
{
	struct node *root = NULL;
	root = insert(root, 8); //This step is V.V.Imp
	insert(root, 3);
	insert(root, 1);
	insert(root, 6);
	insert(root, 7);
	insert(root, 10);
	insert(root, 14);
	insert(root, 4);


	printf("Level order Traversal is :- \n");
	levelorder(root);	
        printf("\n");

	return 0;
}


