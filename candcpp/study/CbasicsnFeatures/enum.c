#include<stdio.h>

/***********************************************
Enums are Names assigned/given to Integers
Names can be States/Error Codes
Advantage: Names make program easy to understand

Enumerations are used for 
Usage: 
For holding different Error codes
For holding different states of the machine like PASS,FAIL
For holding different process states like Ready,Running,Wait,Hold,Block,Terminate
For holding similar data values in string format

Hint: enum is similar to array

Examples:
enum day{mon,tue,wed,thu,fri,sat,sun}; //enum day d=mon;
enum state{pass,fail}; // enum state s=pass;
***********************************************/

#if 1
typedef enum _ERROR_CODES
{
	ERR1 = -5, //default value is 0 
	ERR2, //-4 this value is ERR1+1 = -5+1=-4 automatically  
	ERR3  //-3
}Errcode;

Errcode func(int x) //Error code as return type
{
	if (x==1)
		return ERR1;
	else if (x==2)
		return ERR2;
	else
		return ERR3;
}

void func1(Errcode e) //Error code as Argument
{
	printf("Yes,Please resolve the Error %d\n",e);

}
int main()
{
	Errcode ec;
	ec = func(2) ;
	printf("Error occurred with Error code value is: %d\n",ec);
	func1(ec);
}
#endif

#if 1
typedef enum _Mnth
{
	Jan=10,  //default value is 0
	Feb,     //Remaining enums takes the next incremented integer value
	Mar
}mnth; //short name for this enum


int main()
{
	mnth m; //This is like creating obj for enum
	m = Jan; //We can assign m to all enum strings
	printf("%d\n",m);
}
#endif
