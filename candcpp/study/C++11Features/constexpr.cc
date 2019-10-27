#include<iostream>
using namespace std;

//constexpr are used to evaluate the value of functions or variables at Compile time

constexpr int func(int x,int y)
{
return x*y;
} 

int main()
{
constexpr int x=20;
cout<<x;

//constexpr char* m="Global Edge"; //Error
constexpr char m[] ="Global Edge";
cout<<m;

cout<<func(5,8)<<endl;
}
