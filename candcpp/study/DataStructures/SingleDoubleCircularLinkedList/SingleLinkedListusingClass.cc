#include<iostream>
using namespace std;

/*********************************************************
Use 2 classes 
=> class node with private members -data,next
   public members -constructor,destructor,set,get
=>class LinkedList with private member - head node
   public members -constructor,insert,remove,print

NOTE:
=>Use set,get functions for accessing data,next of node
=>Since head node is a member of class LinkedList,
Do not pass it as a Argument in members functions[insert,remove,print]
*********************************************************/

#if 0
struct node 
{
	int data;
	struct node* next;
};
#endif

//V.V.Imp
class node //this is equivalent to struct node with extra set,get functions
{
	int data; 
	node* next;
	//de* prev; //for DLL

	public:
	node() //constructor
	{}

	~node() //destructor
	{}

       void setData(int x)
       {
	       data= x;
       }

       int getData()
       {
	       return data;
       }

       void setnext(node* y)
       {
	       next= y;
       }

       node* getnext()
       {
	       return next;
       }
};

class LinkedList //Nested class with node class within and member functions insert,remove,print
{
	node *head; //head node declaration,this is a private member we cannot access in main() too 

	public:
	LinkedList() //constructor
	{
		head = NULL;
	}
	//void insert(node *head,int newdata);
	//void remove(node *head);
        //void print(node *head);
        void insert(int newdata); //head of same class Member,so no need to pass it
	void remove();
        void print();

};

//void LinkedList::insert(node *head, int newdata)
void LinkedList::insert(int newdata) //All Setters
{
	node *newnode = new Node();// instead of malloc() 
	//newnode->data = newdata; //data is private member of node class ,so we cannot access directly
	//newnode->next = head; //next is private member of node class ,so we cannot access directly
        newnode->setData(newdata);
        newnode->setnext(head);
	head = newnode;
}

//void LinkedList::remove(node *head)
void LinkedList::Delete() //Getters
{
	node *temp = head;
        //head= head->next;
        //temp->next = NULL;
	head = head->getnext(); //next is private member of node class ,so we cannot access directly
	//temp->setnext(NULL); //next is private member of node class ,so we cannot access directly
	delete temp;
}

//void LinkedList::print(node *head)
void LinkedList::print() //Getters
{
	node *temp =head;
	while(temp != NULL)
	{
		//cout<<temp->data<<endl; //data is private member of node class ,so we cannot access directly
                //temp=temp->next; //next is private member of node class ,so we cannot access directly
		cout<<temp->getData()<<endl;
		temp = temp->getnext();
	}
}

int main()
{
	LinkedList l;
	l.insert(10);
	l.insert(20);
	l.insert(30);
	l.print();
	l.Delete();
	l.Delete();
	l.Delete();
}


