#include<stdio.h>

//Single Linked List[SLL] is represented in C++ using forward_list class container

/*************************************************************************

NOTE:Single linked list needs extra pointer(prev) to delete Nodes
*************************************************************************/

Pending:
a->bc->dc->b->a,Prove this is a Palindrome //Ans: each node data concates to a string array

struct node
{
	int data;
	struct node *next;
};

void Print&CountNodes(struct node *headref)
{
        struct node *temp = headref;
	int count=1;
	while(temp !=NULL)
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
	}while(temp !=NULL);
	printf("%d",count);
}

void insertAtBegin(struct node *headref,int newdata)
{
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next=headref;
	headref=newnode;
}

void insertAfterMiddle(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow= headref;
	while(fast !=NULL && fast->next !=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next =slow->next;
	slow->next=newnode;
}

void insertAfterNthPosition(struct node *headref)
{
	struct node *temp = headref;
	int count =1;//since temp points to head node
	while(temp->next != NULL&&count < N)
	{
		count++;
		temp = temp->next;
	}
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = temp->next;
	temp->next = newnode;
}

void insertAfterEnd(struct node *headref)
{
	struct node *temp = headref;
	while(temp != NULL)
	{
		temp = temp->next;
	}
	struct node *newnode=(struct node*)sizeof(struct node);
	newnode->data = newdata;
	newnode->next = NULL;//Since it is the last node
	temp->next = newnode;
}

void DeleteFirstNode(struct node *headref)
{
	struct node *temp = headref;
	headref =headref->next;
        //temp->next = NULL; //Not needed
	free(prev);
}

void DeleteMiddleNode(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow= headref;
	struct node *prev=NULL;
	while(fast !=NULL && fast->next !=NULL)
	{
		fast = fast->next->next;
		prev=slow; //Preserve the node, then traverse
		slow = slow->next;
	}
	prev->next = slow->next;//slow is the middle node at this point
	free(slow);
} 

void DeleteNthNode(struct node *headref)
{
	struct node *temp = headref;
	struct node *prev=NULL;
	int count =1;//since temp points to head node
	while(temp->next != NULL&&count < N)
	{
		count++;
		prev=temp; //Preserve the node, then traverse
		temp = temp->next;
	}
	prev->next=temp->next;
	free(temp);
}

void DeleteLastNode(struct node *headref)
{
	struct node *temp = headref;
	struct node *prev=NULL; //SLL needs Extra ptr for deletion 
	while(temp->next !=NULL)
	{
		prev=temp; //Preserve the node, then traverse
		temp=temp->next;
	}
	prev->next = NULL;
	free(temp);
}

void ConvertSLLtoCLL(struct node *headref)
{
	struct node *temp=headref;
	while(temp->next != NULL)
	{
		temp =temp->next;
	}
	temp->next=headref;
}

void FindIntersection/MergePoint(struct node *headref) //Using Floyd's Algorithm
{
//clue: Join the end node with start node of shorter linked list 
//to form the circular loop with lesser nodes,to achieve less time complexity
//After finding the intersection point,break the link b/w start and end node of shorter linked list

#if 1 //Assume L1 is shortest Linked list
	struct node* temp1 = head1;
        while(temp1->next != NULL)
        {
	temp1 = temp1->next;
        }
        temp1->next = head1;
#endif
	struct node *fast=headref;
	struct node *slow=headref;
	while(fast !=NULL && fast->next !=NULL) //Floyd's Cycle Detection Algorithm 
	{
		fast=fast->next->next;
		slow= slow->next;
		if(fast == slow)
		{
			printf("Linked List is Circular,It is having Loop");
			break; //Mandatory to break this loop, or else it leads to infinite loop
		}
	}
        
        while(headref->data != slow->data) //Keep comparing both the nodes, by the end of this loop both the nodes data will match
             {
               headref = headref->next;
               slow = slow->next;
             }  
            print("The Intersection/Merge point of 2 Linked lists is %d",slow->data);//headref->data 

#if 1 //After finding the intersection pt, we should remove the loop
        temp1->next = NULL;
#endif
}

void FindMiddleNode2ptrs(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow=headref;
	while(fast !=NULL && fast->next !=NULL) //Floyd's Cycle Detection Algorithm
	{
		fast=fast->next->next;
		slow= slow->next;
	}
	printf("%d",slow->data); //MiddleNode
}
//Time Complexity is O(n)

#if 0 //Doubtful with this
void FindMiddleNode1ptr(struct node *headref)
{
	struct node *temp = headref;
	struct node *mid = headref;
	int count =1;
	while(temp!=NULL)
	{
		count++;
		if(count%2==1)
			mid=mid->next;

		temp=temp->next;
	}
	printf("%d",mid->data); //MiddleNode
}
#endif

//The below function Takes MORE Time complexity, 
//since fastptr and slowptr may not meet in fewer iterations when the loop is having more Nodes say 1Lakh nodes
void FindCircularLoopNRemoveLoop(struct node *headref) 
{
	struct node *fast=headref;
	struct node *slow=headref;
	while(fast !=NULL && fast->next !=NULL) //Floyd's Cycle Detection Algorithm 
	{
		fast=fast->next->next;
		slow= slow->next;
		if(fast == slow)
		{
			printf("Linked List is Circular,It is having Loop");
			break; //Mandatory to break this loop, or else it leads to infinite loop
		}
	}

	struct node *slowprev = NULL;
	while(headref->data != slow->data) //Keep comparing both the nodes, by the end of this loop both the nodes data will match
	{
		headref = headref->next;
		slowprev = slow; //Preserve slow ptr, then traverse
		slow = slow->next;
	}
           slowprev->next = NULL; //Disconnect slowprev from the intersection pt to break the circular loop
}

//Below code takes LESS time irrespective of Nodes in the loop
//Time Complexity O(n) ,Hash Table Implementation
void DetectLoop/DuplicateNodes(struct node* head)
//bool DetectLoop(struct node* head)
{
	unordered_set<node*>s; //Works in C++11 only
	while(head != NULL)
	{
		if(s.find(head) == s.end()) //finding if the node is repeated 
		{
			s.insert(head); //Inserting/Loading the nodes into Hash table[unordered_set]
		}

		cout<<"Loop is present,since Node is repeated\n";
		//return true;
		break;

		head = head->next;
	}
	//return false;
}

void DupNodesCount&RemovalSLL(struct node *headref) //Sorted Linked List
{
	struct node *temp=headref;
	struct node *dup=NULL;
	int count=0;
	while(temp !=NULL && temp->next !=NULL)
	{
		if(temp->data == temp->next->data) //If data matched,Delete the duplicate
		{
			dup = temp->next;
			temp->next = dup->next; //Form the link before deleting the node
			free(dup);
			count++;
		}
		else // If node data is not matched then keep traversing
			temp=temp->next;
	}
	printf("%d",count); //Counts the no. of duplicate nodes 
}
//Time Complexity is O(n)

void DupNodesCount&RemovalUnSLL(struct node *headref) //Unsorted Linked List
{
	struct node *temp1=headref;
	struct node *temp2=NULL;
	int count=0;
	while(temp1 != NULL && temp1->next !=NULL)
	{
		temp2=temp1;  //V.V.V.Imp step 
		while(temp2->next!=NULL)
		{
			if(temp1->data == temp2->next->data) //V.V.Imp
			{
				dup = temp2->next;
				temp2->next = dup->next; //temp2->next=temp2->next->next;
				free(dup);
                                count++;
			}
			else
				temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	printf("%d",count);
}
//Time Complexity is O(n2)

void DeleteAltNodes(struct node *headref)
{
	struct node *alt=NULL;
	while(temp != NULL && temp->next != NULL)
	{
		alt=temp->next;
		temp->next=alt->next; //Form the Link
		free(alt);
		temp = temp->next; //For traversing 
	}
}  
//Time Complexity is O(n)

void DeleteSinglePtrtoNode(struct node *headref) //This is not possible by Single ptr, We need to use 1more ptr
{
	//We have the copy the data and link of next node to ptr pointing Node
	struct node* tmp = ptr->next; //We need extra ptr, WE CANNOT delete SLL using SINGLE PTR 
#if 0 //We can write like this also
	ptr->next=tmp->next;
	ptr->data=tmp->data;
#endif
	ptr->next = ptr->next->next;
	ptr->data = ptr->next->data;
	free(tmp);

#if 1
//Copying the data and delinking the last node
	while(ptr->next->next != NULL)
	{
                ptr->data = ptr->next->data; //Keep copying the data
		ptr=ptr->next;
	}
	ptr->next = NULL; //Last node is removed from sll
#endif
}

//This Works only when the Length/Total no. of nodes in SLL is given 
void FindNthPosNodefromEndofSLL(struct node *headref) //This is not Needed 
{
	struct node *temp = headref;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		if(count == (L-kthPos+1)) //L is length/total no. of nodes in SLL
		{
			cout<<"Node data present at Nth position from End of SLL is:"<<temp->data;
                        break;
		}
		temp = temp->next;
	}
}

//This Works when the Length/Total no. of nodes in SLL is NOT given
void FindNthPosNodefromEndofSLL(struct node *headref)
{
	struct node *fast = headref;
	struct node *slow = headref;

	for(int i=0;i<KthPos;i++) //Move the fast ptr by KthPosition from the beginning 
	{
		fast = fast->next;

	}
	while(fast->next != NULL) //Now Moving fast ptr & slow ptr by each node so that the distance b/w them remains the same
	{
		fast = fast->next;
		slow = slow->next;
	}
	cout<<"Node value at Nth position from End of Linked List is:"<<slow->data;
}
//Time Complexity is O(Kn) //K is No of nodes from the end

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void PairwiseSwap(struct node *headref)
{
	struct node *temp= headref;
	while(temp !=NULL && temp->next !=NULL)
	{
		swap(&(temp->data),&(temp->next->data));
		temp = temp->next->next; //V.V.Imp Step
	}
}
//Time Complexity is O(n)

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

#if 0
void SelectionSort(int x[],int n)
{
        int min=0;
        for(int i=0;i<n-1;i++) //Last element of array is excluded
        {
                min=i;
                for(int j=i+1;j<n;j++) //Sorted element settles at left side,so i+1
                {                      //Left side elements are sorted              
 
                        if(x[j] < x[min])
                                min =j; //Keep overridding this min value index till the end of array
                }
                swap(&x[min],&x[i]); //Sorted element placed at the left side of Array
                //swap(x[min],x[i]); //Since array elements hold address by default
        }
}
#endif

void SelectionSort(struct Node* headref) //Sorting SLL using Selection Sort
{
	struct node *min;
	for(struct node *i=headref; i->next != NULL; i=i->next) //Use '='operator for 3sections,V.V.Imp step
	{
		min = i;
		for(struct node *j=i->next; j != NULL; j=j->next) //*j=i->next, Use '='operator for 3sections, V.V.Imp step
		{
			if(j->data < min->data) //V.Imp condition
				min = j;
		}
		swap(i->data,min->data); //instead of reference,we can use directly,since it is node ptr address inbuilt
		//swap(&i->data,&min->data);
	}
}
//Time Complexity is O(n2),nsquare

void MinMaxNodes(struct node *headref)
{
	struct node *temp = headref;
#if 0
	int max=INT_MAX; //(Max value of integer data type) INT_MAX value is 32767, #include<limits.h>
	int min=INT_MIN; //(Min value of integer data type) INT_MIN value is -32767. #include<limits.h>
#endif

#if 1 //Use this
       int max = headref->data;
       int min = headref->data;
#endif

	while(temp != NULL)
	{
		if(temp->data > max)
		{
			max= temp->data;
		}
		else if(temp->data < min)
		{
			min= temp->data;
		}

		temp= temp->next;
	}
	printf("Maximum Node value in Single linked list is: %d\n",max);
	printf("Minimum Node value in Single linked list is: %d\n",min);
} 

//i/p:10->15->12->13->20->14, Given X= 15,Y=20
//o/p:10->20->12->13->15->14
Only 3steps
void SwapNodeLinksNotNodeData(struct node *headref, int X, int Y) //Swap 2nodes position using links not data
{
        struct node *prevX = NULL;
        struct node *curX = headref;
	while(curX != NULL && curX->data != X) //Traversing till X
	{
		prevX=curX; //saving prev and then traversing
		curX=curX->next;
	}

        struct node *prevY = NULL;
        struct node *curY = headref;
	while(curY != NULL && curY->data != Y) //Traversing till Y
	{
		prevY=curY; //saving prev and then traversing
		curY=curY->next;
	}

#if 0 //Not needed
	if(prevX != NULL) 
	{
		prevX->next = curY; //V.Imp step ,Changing the links
	}
	else
	{
		*headref = curY; //V.V.Imp step
	}

	if(prevY != NULL)
		prevY->next = curX; //V.Imp step,Changing the links
#endif

	prevX->next = curY; //V.Imp step ,Changing the links
	prevY->next = curX; //V.Imp step,Changing the links

	swap(curX->next,curY->next); //Swapping the 2nodes links(next) only,not data
}

void IterativeReverseSLL(struct node *headref)
{
	struct node *temp = headref;
	struct node *y =NULL; //next Node
	struct node *x = NULL; //prev Node
	while(temp != NULL)
	{
		y = temp->next;
#if 0 //Instead of this we are generalising as below
                temp->next = NULL; //for 1st node
#endif
		temp->next = x; //x is NULL only for the 1st node
		x = temp; //For Traversing
		temp = y; //For Traversing
	}
//When temp is NULL,x will be at last node position
	headref = x; //V.V.Imp step,head node pointing to the prev Node
}

#if 1
//Here x is prev
struct node *head; //head should be declared as global ptr
void RecursiveReverseSLL(struct node *x, struct node *temp) 
{
	if(temp == NULL)
	{
		head = x; //Here head is local, declare it as global then only changes will reflect
	}

	RecursiveReverseSLL(temp,temp->next);
	temp->next = x; //When stack REWINDS change connect temp and x(prev)
}

RecursiveReverseSLL(NULL,head); // V.Imp,parameter should be NULL and head 
#endif

struct node* RecursiveReverseSLL(struct node *headref) //Recursive Reverse with node* return type
{
	if(headref->next == NULL)
	{
         return headref;
	}
	struct node *temp = Recursive(headref->next);
	headref->next->next = headref; //Making the last node connect to the previous node using this line of code
	headref->next = NULL;// Making the previous node link as NULL,since we are reversing the linked list
        return temp;
}

void RotateByKnodes(struct node *headref)
{
	//i/p:1->2->3->4->5
	//o/p:4->5->1->2->3
	struct node *temp1 = headref;
	while(temp1 != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = headref; //Making the last node connect with head, forming circular loop

	struct node *temp2 = headref;
        int count = 1;
	while(temp2 != NULL && count <K)
	{
		count++;
		temp2 = temp2->next;
	}
	temp2->next = headref; //Making Kth node next as head
	temp2->next = NULL; //Breaking the Kth node link with head 
}

**************************************************************************
a->b->c->d->c->b->a,Prove this is a Palindrome without using string API's 
**************************************************************************

bool isPalindromeCheck(struct node *x, struct node *y)
{
	while(x && y)
	{
		if(x->data != y->data) //If nodes data is not same, Not Palindrome 
		{
			return false; //V.V.Imp
		}
		x=x->next;
		y=y->next;
	}
	return true; //V.V.Imp,Since all the nodes data is same, Linked list is a Palindrome
}

void Palindrome(struct node *headref)
{
	struct node *fast=headref;
	struct node *slow=headref;
	while(fast !=NULL && fast->next !=NULL) //Floyd's Cycle Detection Algorithm 
	{
		fast=fast->next->next;
                slow_prev = slow; //Preserve the slow ptr and then traverse
		slow= slow->next;
	}
        slow_prev->next = NULL; //V.V.Imp,Disconnect the nodes before middle node
#if 0
fast = NULL //even Nodes
#endif

#if 1  //for Odd no. of Nodes
	struct node *mid = NULL;
	if(fast != NULL)  
	{
		mid = slow;
		slow = slow->next;
                mid->next = NULL; //V.V.Imp,Disconnect the middle node from 2nd half;
	}
#endif

	IterativeReverseSLL(&slow); //Reverse the 2nd half
	if( isPalindromeCheck(headref,slow) == true) 
	{
	cout<<"Given Linked List is a Palindrome\n";
	}
	else
	{
	cout<<"Given Linked List is not a Palindrome\n";
	}

	IterativeReverseSLL(&slow); //Re-Reverse the 2nd half Again to get back the original 2nd half

#if 1  // For both Odd and Even No. of Nodes
	if(mid != NULL) //for Odd No. of Nodes
	{
	slow_prev->next = mid;
	mid->next = slow; 
	}
	else //for Even No. of Nodes
	{
	slow_prev->next = slow;
	}    
#endif
}

L1: 1->3->5
l2: 2->4->6
O/p: 1->2->3->4->5->6
/*
We can also append L2 to L1 1->3->5->2->4->6,then Apply Sorting Technique,But this takes MORE time complexity
*/
struct node* Merge2SortedLinkedLists(struct node *head1,struct node *head2)
{
	SelectionSort(head1); //if L1 is Unsorted
	SelectionSort(head2); //if L2 is Unsorted

	struct node *sort;
	struct node *shead = sort; //preserve sort to a node,making it as head node
	//Here sort keeps traversing in the below code, so preserving it in prior

        if(head1 != NULL && head2 != NULL) //Intially make sort header to point to one of 2 linked lists
        {
                if(head1->data <= head2->data)
                {
                        sort = head1; //sort will always point to the smaller value node
                        head1 = head1->next;
                }
                else
                {
                        sort = head2;
                        head2 = head2->next;
                }
        }

	while (head1 != NULL && head2 != NULL) //Keep traversing in both the Linked lists
        {
                if(head1->data <= head2->data)
                {
                        sort->next = head1; //V.V.Imp step
                        sort = head1;
                        head1 = head1->next;
                }
                else
                {
                        sort->next = head2; //V.V.Imp step
                        sort = head2;
                        head2 = head2->next;
                }
        }

#if 1 //If Extra nodes are present in linked list2 and linked list1
        if(head1 != NULL) //V.V.Imp step, head1 is having any node
                sort->next = head1;
        else if(head2 != NULL) //V.V.Imp step, head2 is having any node
                sort->next = head2;
#endif
        return shead;
}

struct node* insertNode(int data)
{
	struct node* Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->data=newdata;
	Newnode->next=NULL;
	return Newnode;
}

//Addition of linked lists is head to head,from Left side to Right side
//Whereas Normal Numbers addition is from from Right side to Left side
struct node* AdditionOfNodesin2SLLists(struct node *head1,struct node *head2)
{
	int sum;
	int carry=0;
	struct node *temp,*temp1;
        struct node *temphead =temp;  //preserve temp to a node,making it as head node
	//Here temp keeps traversing in the below code, so preserving it in prior

	while(head1 !=NULL || head2 !=NULL) //V.V.Imp, Any one of the linked lists should have data
	{
		sum = (head1?head1->data:0) + (head2?head2->data:0) + carry;
		carry = (sum >= 10)?1:0;
		sum = sum%10; //we will kp only remainder
		temp=insertNode(sum); //Form a New node using this sum as newdata

#if 1 //for forming linked lists with sum as data           
		temp1->next=temp;
		temp1=temp; //for traversing
#endif                

		if(head1 != NULL) //Traverse if node is present
			head1 = head1->next;
		if(head2 != NULL) //Traverse if node is present
			head2 = head2->next;
	}
	if(carry>0) //If carry is still present,even after completion of head1->data,head2->data
	{
		temp->next=insertNode(carry);//Node having carry as data
	}
	return temphead;
}

int main()
{
	struct node *head = NULL;
	insertAtBegin(head,5);
	insertAtBegin(head,6);
	while(head->next)
	{
		printf("%d",head->data);
		head = head->next;
	}
}


