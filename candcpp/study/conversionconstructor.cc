#include<iostream>
using namespace std;

class X
{
  int m;
  public:
  X(int k)
  {
    m=k;
    cout<<"In Param constructor\n";
  }

  void display()
  {
    cout<<m<<endl;
  }
};

int main()
{
  X obj=10; //Param constructor will be called
  obj.display();

  obj=20; //This will convert 20(int) to class type,Param constructor will be called
  obj.display();
}


