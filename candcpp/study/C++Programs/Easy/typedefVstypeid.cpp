#include<iostream>
using namespace std;
#include<typeinfo> //typeid().name()

/**************************************************************
typedef[Alias] and typeid[RTTI]
typeid()- This is a operator used to get the data type of the object at Run time[RTTI]

typedef-It is like giving alias/new nme to the data type
int x=10;
 (or)
typedef int M;
M x=10;
**************************************************************/

#if 0
struct S
{
	int x;
}; 
#endif

#if 1 //using typedef
typedef struct S
{
	int x;
}st; //This is alias name for struct S
#endif

int main()
{
#if 0
	struct S obj;
#endif

#if 1 //using typedef
	st obj; //We can avoid typing data type 
#endif 
	obj.x =10;
	cout<<obj.x<<endl;
	cout<<typeid(st).name()<<endl;


#if 0
	int x =10;
#endif

#if 1 //using typedef
	typedef int M;
	M x=10;
#endif
	cout<<"After typedef to int: "<<x<<endl;

}
