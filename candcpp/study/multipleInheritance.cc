#include<iostream>
using namespace std;

class A
{
  public:
    A()
    {
      cout<<"In Cons A\n";
    }

    ~A()
    {
      cout<<"In Des A\n";
    }
};

class B:public A
{
  public:
    B()
    {
      cout<<"In Cons B\n";
    }

    ~ B()
    {
      cout<<"In Des B\n";
    }

};

class C: public B
{
  public:
    C()
    {
      cout<<"In Cons C\n";
    }

    ~ C()
    {
      cout<<"In Des C\n";
    }

};

int main()
{
  C obj;
  C *ptr = new C();
  delete ptr;
}
