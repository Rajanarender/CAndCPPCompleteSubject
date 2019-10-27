#include<iostream>
using namespace std;
#include<assert.h>

//#define NDEBUG -assert can be disabled at compile time using this macro

/****************************************************************************
assert:These are the conditional assumptions made by the user
If the assert condition gets failed, then the program gets aborted/exited

NOTE:
assert on failure calls abort() function which in turn terminates the program
assert creates run time error[Segmentation fault core(dumped)]
*****************************************************************************/

int main()
{
	int x =5;
	assert(x==10);
	cout<<"Global Edge\n"<<endl;
}
