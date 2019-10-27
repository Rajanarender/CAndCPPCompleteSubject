#include<iostream>
using namespace std;

/**************************************************************************
Converting Derived to Base class is possible
Converting Base to Derived class is not possible
NOTE: Due to this, only Base ptr is used for accessing Base,Derived members
****************************************************************************/

class Base
{
	public:
		void func()
		{
			cout<<"In Base func\n";
		}
      
                virtual void v_func()
		{
			cout<<"In Base v_func\n";
		}
};

class Derived:public Base
{
	public:
		void func1()
		{
			cout<<"In Derived func1\n";
		}
#if 1
                void v_func()
		{
			cout<<"In Derived v_func\n";
		}
#endif
};

int main()
{
#if 0  //1st way,dynamically
        Base *ptr=new Derived(); //dynamic object creation
#endif

#if 0 //2nd way,dynamically
        Derived *d;
        Base *ptr=dynamic_cast<Base*>(d);//Upcasting
#endif

#if 0 //3rd way,statically
        Derived *d;
        Base *ptr= d;
#endif

        ptr->func();
        ptr->v_func(); //1st Base ptr will check whether the func is virtual,
                       //2nd if it is overridden in Derived,it will call Derived func
                       //3rd if not overridden in Derived,it will call Base func only,V.Imp

        Derived d;//1st Derived will check whether that particular func is present within it
                  //if present, it will call Derived func only
                  //if not present, it will call Base func(including virtual func),V.Imp
        d.v_func();
        d.func1();
        d.func();

#if 0
      Base *ptr=new Base();
      Derived *dptr=dynamic_cast<Derived*>(ptr);//No Error
      if(dptr)
      dptr->v_func(); 
#endif

#if 0 //Converting Base to Derived, throws error
      Derived *dptr = new Base(); //Error,Invalid conversion from Base* to Derived*

      Base b;
      Derived *dptr=&b;//Error,Invalid conversion from Base* to Derived*
      dptr->v_func(); //It calls Derived func only
#endif
}
