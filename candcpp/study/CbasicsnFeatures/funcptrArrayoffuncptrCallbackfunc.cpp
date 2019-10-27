#include<iostream>
using namespace std;

NOTE:
Backslash(\) is used for endofline(\n)tabspace(\t),null character('\0')
char *x = NULL;[NULL is a Macro]
char *x = '\0';[Backslash followed with Zero]
Relational Operators are ==,!=,>=,<= [We should never separate them]
left shift - <<
right shift - >>


/*==============
  Function ptr
===============*/
void get(int x)
{
	cout<<x;
}

void (*func)(int)=get;
cout<<func(10);
cout<<(*func)(10); //this also works fine
(or)
void (*func)(int)=&get;
cout<<(*func)(10);

/*================
Callback functions:
================*/
int get(int x)
{
	return x;
}

int callback(int(*fptr)(int x),int y)
{
	return(fptr(3)+y);
}

int main()
{
	int(*fptr)(int)=get; //int(*fptr)(int)=&get;
	cout<<fptr(1)<<endl; //cout<<(*fptr)(1)<<endl;
	cout<<callback(get,2)<<endl; //Call back function,function passed as argument in other function
}

/*==============================
Pointer to a function:
===============================*/
int *func()
{
	static int x =10;
	return &x;
}

int*x= func();

/*==============================
  Array of function ptrs
  ===============================*/
int get1(int x)
{
	return x;
}

int get2(int y)
{
	return y;
}

int get3(int z)
{
	return z;
}

int main()
{
	int(*fptr[])(int)={get1,get2,get3};
	cout<<fptr[0](5)<<endl;
	cout<<fptr[1](6)<<endl;
	cout<<fptr[2](7)<<endl;

	for(int i=0;i<3;i++)
	{
		cout<<func[i](5);
	}
}

---------------------------------------------------------------------------------------------
Perform addition and subtraction functions using array of function ptrs:
----------------------------------------------------------------------------------------------
void sum(int a ,int b)
{
cout<<a+b;
}
 
void min(int a ,int b)
{
cout<<a-b;
}
 
void (*func[])(int)={sum,min};
cout<<func[0](7,8);
cout<<func[1](7,8);
cout<<func[2](7,8);
 
  (or)
   
for(int i=0;i<2;i++)
{
cout<<func[i](5);
}

/*===================================
  Array of ptrs
  ====================================*/
int main()
{
	int arr[5]={2,4,6,8,9};
	int (*ptr)[5]= &arr; //&arr,here '&' should be used definitely,or else throws Error[casting of int to int*]
	cout<<(*ptr)[4]<<endl;

	for(int i=0;i<5;i++)
	{
		cout<<(*ptr)[i]<<",";
	}
}

/*====================================
  ptr to Array
  =====================================*/

int main()
{
#if 0
       int arr[5]={2,4,6,8,9};
       int *ptr =arr;
       cout<<*ptr<<endl;

       for(int i=0;i<5;i++)
       {
       cout<<*ptr<<",";
       ptr++;
       }
#endif

    char x[]="GLOBAL";
    char *ptr=x;

    while(*ptr!= '\0') //while(*ptr)
    {
        cout<<*ptr<<",";
        ptr++;
    }
}

/*=========================================
  Array of class objects
 ==========================================*/
class Base
{
	int x;
	static int y;
	public:
	Base()
	{
		x=1;
		y=2;//We can intialize static member without scope resolution operator
	}
	Base(int a,int b)
	{
		x=a;
		y=b;
	}

	void display()
	{
		cout<<x<<endl;
		cout<<Base::y<<endl;
	}

};

Base::y=10;//definition of static variable is must

int main()
{
	Base arrayobj[3];//We can call only default constructor using Array of class objects
	//arrobj[5]={{7,8}}; //Calling parameterised constructor using Array of class objects,C++11 feature
	arrobj[0].display();
}
