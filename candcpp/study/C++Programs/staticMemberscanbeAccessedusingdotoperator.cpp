#include<iostream>
using namespace std;

class X
{
  public:
    static int k;
    static void func()
    {
      cout<<"in func\n";
    }
};

int X::k=10;

int main()
{
  X obj;
  cout<<sizeof(X)<<endl;
  cout<<X::k<<endl;
  cout<<obj.k<<endl;
  X::func();
  obj.func();
}
