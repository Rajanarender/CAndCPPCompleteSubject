#include<iostream>
using namespace std;
#include<string.h>

/**************************************
a->bc->d->dcb->a
(or)
a->b->c->b->a

char x[10] = {0};

while(head)
{
strcat(x,head->data) //abcdcba, Do not take x[i]
head=head->next;
}

IsPalindrome();
**************************************/

struct Node
{
	Node* next;
        char data[5]; //Take length as per the maximum size of node data
};

void Palindromefunc(char *m)
{
	char *start = m;
	char *end = m+strlen(m)-1;
	while(start < end)
	{
		if(*start != *end)
		{
			cout<<"Linked list is not a Palindrome"<<endl;
			return; //V.V.Imp step
		}
           start++;
           end--;
	}
	cout<<"Linked list is a Palindrome"<<endl;
        return;
}

void printList(Node *node)
{
	char x[10]={0};//V.Imp,Make the base index to zero,So as to avoid the garbage value while concatinating with the node data          
	while (node != NULL)
	{
		cout << node->data << " -> "; //Not necessary,just to print on console
		strcat(x,node->data); //here x base address is taken,V.V.Imp DO not take x[i] 
		//memset(node->data,0,sizeof(char)*strlen(node->data));
		node = node->next;
	}
	cout<<"NULL"<<endl; //Not necessary,just to print on console
	cout<<x<<endl;
        Palindromefunc(x);

#if 0 //Std Palindrome implementation , we cannot use this here
	char temp[10];
	strcpy(temp,x);
	strrev(temp);
	if(strcmp(temp,x) ==0)
		cout<<"Linked list is a Palindrome"<<endl;
	else
		cout<<"Linked list is not a Palindrome"<<endl;
#endif
}

Node *newNode(const char *s) //const char *s is V.V.Imp
{
	Node *new_node = new Node;
        strcpy(new_node->data,s); //V.V.Imp 
     
	new_node->next = NULL;
	return new_node;
}

int main()
{
	
	Node *head = newNode("a");
	head->next = newNode("bc");
	head->next->next = newNode("d");
	head->next->next->next = newNode("dcb");
	head->next->next->next->next = newNode("a");
        printList(head);
}

