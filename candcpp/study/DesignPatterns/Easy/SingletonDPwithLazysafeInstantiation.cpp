#include<iostream>
using namespace std;
#include<pthread.h> //for mutex

/*****************************************************
Design patterns:3Types
Creational -Singleton,Factory,Abstract Factory
Behavioral -Observer
Structural -Proxy,Adapter

UML Diagrams:
Behavioral - State Machine,Sequence,Use case Diagrams
Structural - Class,Object,Composition diagrams
******************************************************/

/*********************************************
Main Objective "To Create only one Object to that class than multiple objects"
Dynamic Singleton using pointers
Singleton implementation dynamically:
We use static ptr to achieve this
Calling the constructor from static function
ptr=new Sgtn();
**********************************************/
//Cons,Des,copy cons,assignment operator should be private to achieve this
#if 1
class Sgtn
{
#if 0 //This is wrong,declarations only, instead define them
	Sgtn();
       ~Sgtn();
	Sgtn(const Sgtn &);
	Sgtn& operator=(const Sgtn &);
#endif

#if 1 //Currect format
	Sgtn() {}
       ~Sgtn() {}
	Sgtn(const Sgtn &) {}
	Sgtn& operator=(const Sgtn &) {}
#endif
	static Sgtn *ptr;
        public: 
	static Sgtn *getinstnce(); //should be public,then only we can access from main()
};

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
Sgtn* Sgtn:: ptr = NULL;
Sgtn* Sgtn:: getinstnce()
{
	if(ptr == NULL)
	{
	        pthread_mutex_lock(&m); //V.V.Imp step,we need to lock the mutex 
		ptr = new Sgtn(); //Constructor call dynamically
		pthread_mutex_unlock(&m); //V.V.Imp step, we need to unlock the mutex before return
		return ptr;
	}
	else
	{
		cout<<"Only one instance can be created"<<endl;
		return ptr;
	}
}

int main()
{
	Sgtn *ptr1=Sgtn::getinstnce();
	Sgtn *ptr2=Sgtn::getinstnce();
	return 0;
}
#endif
/*********************************************
Static Singleton using references
Lazy and Safe Instantiation of Singleton Implementation:
=======================================
Singleton implementation statically:
We use static object to achieve this
Calling the constructor from static function
static Sgtn obj();
**********************************************/
//Below code doesnot work
#if 0
class Sgtn
{
	Sgtn()
        {
         cout<<"Only one instance can be created"<<endl;
        }
       ~Sgtn();
	Sgtn(const Sgtn &);
	Sgtn& operator=(const Sgtn &);

        public: 
	static Sgtn& getinstnce();//should be public,then only we can access from main()
};

//Sgtn* Sgtn:: ptr = NULL;
Sgtn& Sgtn::getinstnce() //Reference return type
{
        static Sgtn obj; //obj should be static,since static func uses static variables only
                         //Calls the constructor statically

        //Sgtn &obj=new Sgtn;
        return obj;
}


int main()
{
	//Sgtn a,b; //Error,since this calls constructor which is private
	Sgtn &a=Sgtn::getinstnce(); //using Reference will not call constructor directly
	Sgtn &b=Sgtn::getinstnce();
	return 0;
}
#endif
