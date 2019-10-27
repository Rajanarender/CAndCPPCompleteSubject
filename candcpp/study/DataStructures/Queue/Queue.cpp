#include<iostream>
using namespace std;

/***************************************************************
Queue using Array
Queue using class
Queue using Single Linked list[nothing but ptr]
Queue using Stacks

NOTE: STL deque container class =  Queue(double-ended)
*****************************************************************/

/********************************************
Queue implementation using Array,class
********************************************/

#define MAX 5
int Q[MAX];
int front = -1;
int rear = -1;

void Enqueue(int x) //In STL,this is push_front()
{
	if(rear >= MAX-1)
	{
		cout<<"Queue Overflow\n";
                return;
	}
	Q[++rear] =x;

#if 0 //We can write like this also
	rear++;       
	Q[rear] = x;
#endif
	front = 0; //V.V.V.Imp,Since front advances by +1, when the 1st element is Enqueued
}

int Dequeue() //V.V.Imp. In STL, this is pop_front(), pop_front() erases the element but does not return it
{
	if(front <= -1)
	{
		cout<<"Queue Underflow\n";
                return 0;
	}

	return Q[front++];

#if 0 //We can write like this also
	front++;       
	return Q[front];
#endif

}

int main()
{
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
        cout<<Dequeue()<<endl;
        cout<<Dequeue()<<endl;
}

/********************************************
Queue implementation using Single Linked List
********************************************/
#if 1 
struct node
{
	int data;
	struct node *next;
};


void Enqueue(struct node *front,struct node *rear,int newdata)
{
	struct node *newnode= (struct node*)malloc(sizeof(struct node));
        newnode->data = newdata; 
	newnode->next = NULL; //V.V.Imp 

	if(rear == NULL) //If Queue is Empty at the start of insertion
	{
		front = rear= newnode; //V.V.Imp. Both front and rear ptrs point to the same node 
                return;
	}
        rear->next = newnode; //V.V.Imp, rear keeps moving
	rear = newnode;
}

int Dequeue(struct node *front,struct node *rear)
{
	if(front == NULL) //If Queue is Empty
	{
		rear = NULL; //Make rear also NULL
		return;
	}
	struct node *temp=front;
	front = front ->next;

	int x = temp->data; //Preserve the queue data
	temp->next =NULL;
	free(temp);
	return x;
}


int main()
{
	struct node *front=NULL,*rear=NULL;
	Enqueue(front,rear,5);
	Enqueue(front,rear,6);
	Enqueue(front,rear,7);
	Enqueue(front,rear,8);
	cout<<Dequeue(front,rear);
	cout<<Dequeue(front,rear);
	cout<<Dequeue(front,rear);
	cout<<Dequeue(front,rear);
}
#endif




