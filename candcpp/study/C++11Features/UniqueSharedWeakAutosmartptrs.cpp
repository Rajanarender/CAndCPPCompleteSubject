#include<iostream>
using namespace std;
#include<memory> //V.V.Imp header for smart ptrs

/**************************************************************************
Smart ptrs are used to avoid Memory Leaks and Segmentation faults
Generally we allocate memory and forget to release it,due to which Memory leaks occurs
Smart ptrs are smart in releasing the memory AUTOMATICALLY once the object goes out of scope

Smart ptrs are 4types:
syntax:
unique_ptr<X>p1(new X); //X is data type, classname
shared_ptr<X>p1(new X); //X is data type, classname
weak_ptr<X>p1(new X); //X is data type, classname
auto_ptr<X>p1(new X); //X is data type, classname
***************************************************************************/

#if 0
int main()
{
	shared_ptr<int>s1(new int),s2;
	cout<<s1.use_count()<<endl; //1
	cout<<s2.use_count()<<endl; //0, no byte data

        s2=s1; //unique_ptr& operator=(const shared_ptr&) = delete 	
        shared_ptr<int>s3(s2); //shared_ptr(const shared_ptr&) = delete

	cout<<s1.use_count()<<endl; //3
	cout<<s2.use_count()<<endl; //3
	cout<<s3.use_count()<<endl; //3

	s1.reset();
	cout<<s1.use_count()<<endl; //0
	cout<<s2.use_count()<<endl; //2
	cout<<s3.use_count()<<endl; //2

	unique_ptr<int>u1(new int),u2;
        //cout<<u1.use_count()<<endl; //Error since no reference count concept in unique_ptr

/*
        u2=u1;                 //Error since unique_ptr& operator=(const unique_ptr&) = delete;
	unique_ptr<int>u3(u1); //Error since unique_ptr(const unique_ptr&) = delete;
*/

	weak_ptr<int>w1; //TBD
	cout<<w1.use_count()<<endl; //TBD
}
#endif

class X
{
	public:
		X()
		{
			cout<<"Constructor called\n";
		}

		~X()
		{
			cout<<"Destructor called\n";
		}

		void display()
		{
                        cout<<"Testing smart ptrs\n";
		}
};

int main()
{
#if 1
	//unique_ptr<X> u1(new X); //this is 1 way of declaration

        //This is other way of declaration
        unique_ptr<X>u1;
        u1.reset(new X);
#endif
        unique_ptr<X>u2;
	u1->display();
	//u2=u1; //assignation,copying not allowed in unique_ptr

	shared_ptr<X>s1(new X),s2;
	s1->display();
	s2=s1; //assignation,copying is allowed in shared_ptr

#if 0
	auto_ptr<X>a1(new X),a2;
	a2 = a1;
        cout<<a1.get()<<endl;
        cout<<a2.get()<<endl;
#endif
}
