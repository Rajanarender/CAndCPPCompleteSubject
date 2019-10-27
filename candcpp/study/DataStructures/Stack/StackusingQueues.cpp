#include<iostream>
using namespace std;

/*****************************************************
Stack using queues:
Push : 
Enque1()

Pop :
=>Enque2( Deque1() ); //Deque all elements in Queue1 except the last one
=>Now return Deque1(); //Dequeing the last element of Queue1 

=>Enque1( Deque2() ); //Deque all elements in Queue2 except the last one
=>Now return Deque2(); //Dequeing the last element of Queue2

=>Keep repeating the above 4steps till both the Queues are Empty

FYI: The below code is just for idea and it does not work as expected 
*****************************************************/

#define MAX 5

int Q1[MAX];
int Q2[MAX];

int front1 = -1;
int rear1 = -1;

int front2 = -1;
int rear2 = -1;

void Enque1(int x)
{
	Q1[++rear1]=x; //V.V.Imp,Fill the Stack 
        front1 = 0; //V.V.Imp
}

void Enque2(int y)
{
 	Q2[++rear2]=y;
        front2 = 0; //V.V.Imp    
}

int Deque1()
{
	return Q1[front1--];	
}

int Deque2()
{
	return Q2[front2--];	
}

int count=0; //count for number of elements Enqueue()
int flag =0; 
int Pop()
{
	if (flag == 0) //Only one time all elements of S1 should be popped and pushed completely into S2 
	{ 
		for(int i=0;i<count-1;i++)
		{
			//int y = pop1();
			//push2(y);
			Enque2( Deque1() ); //We can write like this also
		}
		flag = 1;
	}

	//int z= Deque1();
	//return z;
	return Deque1(); //We can write like this also
}

void Push(int x)
{
	Enque1(x);
	count++;
	flag =0;
}

int main()
{
	Push(10);
	Push(20);
	Push(30);
	Push(40);
	cout<<Pop()<<endl;
	cout<<Pop()<<endl;
	cout<<Pop()<<endl;
	cout<<Pop()<<endl;
}
