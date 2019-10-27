#include<iostream>
using namespace std;
#include<stdlib.h> //malloc,free

/*******************************************************
To avoid/restrict the object creation dynamically
=>make new operator overloading function private
=>Both the new and delete operator functions are static by default

NOTE: Since both the operator functions are static by default,
these functions cannot access this ptr. 
*******************************************************/

#if 1
class Test
{
	int x;

	public:
	Test()
	{
		cout<< "Default constructor is called\n";
		x=0;
	}

	private:
	static void* operator new(size_t size) //static is important
	{
                cout<<"new operator is overloaded "<<endl;
		//void *p = ::new Test(); //This is wrong
		void *p = malloc(size); //V.V.Imp step
		return p;
	}

	static void operator delete(void *q) //static is important
	{
                cout<<"delete operator is overloaded "<<endl;
		free(q); //V.V.Imp step
	}

};

int main()
{
#if 1 //This allocates memory using new operator overloading and then calls Default Constructor Explicitly
	Test *obj = new Test(); 
	delete obj;
#endif
}
#endif

/*******************************************************
To avoid/restrict the object creation statically
=>make constructor[default,parameterised,copy]
=>make assignment operator as private
*******************************************************/

#if 0
class Test
{
	private:
		Test(); //Default Constructor
		Test(int a); //Parameterised Constructor
		Test(const Test &); //Copy Constructor
		Test& operator=(const Test &); //Assignment operator
};

int main()
{
	Test t(10);
}
#endif


