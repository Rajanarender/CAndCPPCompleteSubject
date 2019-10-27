#include<iostream>
using namespace std;

/*************************************************
reference vs ptr: 5 differences
1)Declaration and initialization
2)NULL initialization
3)Re-assignation [original variable assigned to reference gets affected]
4)Arithmetic operation [original variable assigned to reference gets affected]
5)Memory address
6)Multiple levels of Indirection

Reference is used mainly:
=>to modify local variables
=>to avoid object slicing
=>Used in copy constructor
=>Used in assignment operator
=>Used in avoiding copying of object to object in function parameters 
*************************************************/

int main()
{

#if 0 //Declaration and initialization 
int k =10; 
int &x; //Error
int &x = k; //Correct,Must be initialized during declaration only

int *ptr = &k; //Declaration+initilialization
(or)
int *ptr; //Declaration only
ptr = &k; //Initialization separately
#endif

#if 0 //Intialization to NULL
int &x = NULL; //Error,cannot initialize reference to NULL

int *ptr = NULL; //Can be initialized to NULL
#endif

#if 0 //Re-assignation
int k =10; 
int &x = k;
int y =20;
k =y;
cout<<x<<k<<y<<endl; //k value gets affected due to Re-assignation


int *ptr = &k;
ptr = &y;  //Re-assignation works without affecting k value
#endif


#if 0 //Arithmetic operation
int k =10; 
int &x = k;
(x)++; //k value gets affected due to arithmetic operation
cout<<x<<" "<<k<<endl; 

int *ptr = &k;
ptr++; //Increment the ptr will not affect the variable
cout<<*ptr<<endl; 
#endif

#if 1 //Memory address
int k =10; 
int &x = k;
cout<<&x<<" "<<&k<<endl; //address of reference and variable are same


int *ptr = &k;
cout<<&ptr<<" "<<&k<<endl; //address of ptr and variable are different
#endif

#if 0 //Multiple Levels of Indirection
int k =10; 
int &x = k;
int &x1= x; // only 1level

int *ptr = &k;   //1st level, single ptr
int **ptr1 = &ptr; //2nd level, double ptr
int ***ptr2= &ptr1; //3rd level,triple ptr
#endif
}
