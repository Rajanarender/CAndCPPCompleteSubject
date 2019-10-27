
/***********************************************************
Circular Linked List:
=>Traversing using condition if(temp->next != head)
instead of if(temp->next != NULL)
=>Inserting/Deleting nodes at Beginning,End are Different
Remaining all operations are similar to Single Linked List

In Circular Linked List,we have 2 scenarios for Inserion of nodes at begin
=>Empty CLL, with head == NULL
=>CLL with few nodes already existing

NOTE: For deletion of any node in CLL, we need extra ptr similar to SLL
***********************************************************/
struct node
{
	int data;
	struct node *next;
};

void Print&CountNodes(struct node *headref) //Same as SLL
{
        struct node *temp = headref;
	int count=1;
	//while(temp !=NULL)
	while(temp->next != headref)
	{
		count++;
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("%d",count);

    (or)
	int count=0;
        do
	{
		count++;
		printf("%d",temp->data);
		temp=temp->next;
	//}while(temp !=NULL);
	}while(temp->next != headref);
	printf("%d",count);
}

void insertAtBegin(struct node *headref,int newdata) //Different,Important 
{
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;

	if(headref == NULL) //Only Single Node
	{ 
		newnode->next = newnode; //In SLL, newnode->next = NULL
	        headref = newnode;
	}
	else
	{
                struct node *temp = headref;
		while(temp->next != headref); //Traverse till the last node 
		{
			temp = temp->next;
		} 
		temp->next = newnode; //V.V.imp step 
		newnode->next = headref;
	        headref = newnode;
	}
}

void insertAfterMiddle(struct node *headref) //Same as SLL
{
	struct node *fast=headref;
	struct node *slow= headref;
        struct node *temp=headref;
	//while(fast !=NULL && fast->next !=NULL)
	while(fast !=NULL && fast->next !=NULL && temp->next != headref)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = slow->next;
	slow->next = newnode;
}

void insertAfterNthPosition(struct node *headref) //Same as SLL
{
	struct node *temp = headref;
	int count =1;//since temp points to head node
	//while(temp->next != NULL&&count < N)
	while(temp->next != headref && count < N)
	{
		count++;
		temp = temp->next;
	}
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = temp->next;
	temp->next = newnode;
}

void insertAfterEnd(struct node *headref) //Different,Important
{
	struct node *temp = headref;
	while(temp->next= headref)
	{
		temp = temp->next;
	}
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
        temp->next = newnode;
	newnode->next = headref;//Since it is the last node
}

void DeleteFirstNode(struct node *headref) //Different,Important
{
	struct node *temp = headref;
        while(temp->next != headref)
         {
           temp=temp->next;
          }
        
        temp->next = headref->next; //V.V.Imp step
        struct node *prev = headref; //V.V.Imp step
        headref = headref->next; //headref is preserved to next position
        prev->next = NULL; //V.V.Imp step 
	free(prev);
}

void DeleteMiddleNode(struct node *headref) //Same as SLL
{
	struct node *fast=headref;
	struct node *slow= headref;
	struct node *prev=NULL;
        struct node *temp = headref;
	//while(fast !=NULL && fast->next !=NULL)
	while(fast !=NULL && fast->next !=NULL && temp->next != headref)
	{
		fast = fast->next->next;
		prev=slow; //Preserve the node, then traverse
		slow = slow->next;
	}
	prev->next = slow->next;//slow is the middle node at this point
	free(slow);
} 

void DeleteNthNode(struct node *headref) //Same as SLL
{
	struct node *temp = headref;
	struct node *prev=NULL;
	int count =1;//since temp points to head node
	//while(temp->next != NULL&&count < N)
	while(temp->next != headref &&count < N)
	{
		count++;
		prev=temp; //Preserve the node, then traverse
		temp = temp->next;
	}
	prev->next=temp->next;
	free(temp);
}

void DeleteLastNode(struct node *headref) //Different,Important
{
	struct node *temp = headref;
	struct node *prev=NULL; //SLL needs Extra ptr for deletion 
	//while(temp->next !=NULL)
	while(temp->next != headref)
	{
		prev=temp; //Preserve the node, then traverse
		temp=temp->next;
	}

        prev->next = temp->next;
        free(temp);
#if 0
        prev->next =headref; //V.V.Imp step
        temp->next = NULL; // V.V.Imp step
#endif
	free(temp);
}

void ConvertCLLtoSLL(struct node *headref)
{
	struct node *temp=headref;
	//while(temp->next != NULL)
	while(temp->next != headref)
	{
		temp =temp->next;
	}
	//temp->next=headref;
	temp->next = NULL; //This will break the continuity
}

void IterativeReverseCLL(struct node *headref)
{
	struct node *temp = headref;
	struct node *y =NULL; //next Node
#if 0 // In SLL
	struct node *x = NULL; //prev Node
#endif
	struct node *x; //prev Node shouldn't be initialized to NULL in CLL

	//while(temp != headref) //Shouldnot use this,as it fails in the beginning of CLL
        while(temp->next != headref)
	{
		y = temp->next;
		temp->next = x; //x cannot be NULL for the 1st node in CLL
		x = temp; //For Traversing
		temp = y; //For Traversing
	}
//When temp is NULL,x will be at last node position
        headref->next =x; //Form the link b/w head node and last node
	headref = x; //V.V.Imp step,head node pointing to the prev Node
}
