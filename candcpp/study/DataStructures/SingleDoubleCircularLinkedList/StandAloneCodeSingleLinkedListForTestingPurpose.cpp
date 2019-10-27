// Program to find smallest and largest
// elements in singly linked list.
#include <bits/stdc++.h>
using namespace std;
//#include<unordered_set>

/* Linked list node */
struct Node {
	int data; //char data for characters as data
	struct Node* next;
};

// Function that push the element in linked list.
void push(struct Node** head, int data)
{
	// Allocate dynamic memory for newNode.
	struct Node* newNode = 
		(struct Node*)malloc(sizeof(struct Node));

	// Assign the data into newNode.
	newNode->data = data;

	// newNode->next assign the address of
	// head node.
	newNode->next = (*head);

	// newNode become the headNode.
	(*head) = newNode;
}

#if 0
void DetectLoop(struct Node* head)
{
	unordered_set<Node*>s;
	while(head != NULL)
	{
		if(s.find(head) != s.end())
		{
			cout<<"Loop is present,since Node is repeated\n";
			break;
		}

		s.insert(head);
		head= head->next;
	}
}
#endif
 
// Display linked list.
void printList(struct Node* head)
{
	while (head != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	cout << "NULL" << endl;
}

// Drier program to test the functions
int main()
{
	// Start with empty list
	struct Node* head = NULL;

	// Using push() function to construct
	// singly linked list
	// 17->22->13->14->15
	push(&head, 15);
	push(&head, 14);
	push(&head, 13);
	push(&head, 22);
	push(&head, 17);
#if 0
        head->next->next->next->next->next=head;
        DetectLoop(head);
#endif
	cout << "Linked list is : " << endl;

	// Call printList() function to display
	// the linked list.
	printList(head);
	return 0;
}

