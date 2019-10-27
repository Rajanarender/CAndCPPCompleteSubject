#include<iostream>
using namespace std;
/*****************************************************
Queue using stacks:
Enqueue : 
push1()

Dequeue :
push2( pop1() );
pop2();

*****************************************************/

#define MAX 5

int S1[MAX];
int S2[MAX];

int top1 = -1;
int top2 = -1;

void push1(int x)
{
	S1[++top1]=x; //V.V.Imp,Fill the Stack 
}

void push2(int y)
{
	S2[++top2]=y;
}

int pop1()
{
	return S1[top1--];	
}

int pop2()
{
	return S2[top2--];	
}

int count=0; //count for number of elements Enqueue()
int flag =0; 
int Dequeue()
{
	if (flag == 0) //Only one time all elements of S1 should be popped and pushed completely into S2 
	{ 
		for(int i=0;i<count;i++)
		{
			//int y = pop1();
			//push2(y);
			push2( pop1() ); //We can write like this also
		}
		flag = 1;
	}

	//int z= pop2();
	//return z;
	return pop2(); //We can write like this also
}

void Enqueue(int x)
{
	push1(x);
	count++;
	flag =0;
}

int main()
{
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	cout<<Dequeue()<<endl;
	cout<<Dequeue()<<endl;
	cout<<Dequeue()<<endl;
	cout<<Dequeue()<<endl;
}
