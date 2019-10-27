#include<iostream>
using namespace std;

/***********************************************
We need to use 
=>local buf variable to store the reverse characters
=>Make local buf to '\0' and then return local buf
***********************************************/

#if 1 //Here string gets reversed 
char* func(char *x)
{
        //char revbuf[10]; //Since we are returning it,make it static or else leads to Segmentation Fault
	static char revbuf[10]; 
	static int i=0; //Since i keeps changing, make it static
	if(*x)
	{
		func(x+1);
#if  1 //V.V.imp step,Once the string reaches '\0' character,stack frames keep popin out in reverse of the string              
		revbuf[i] = *x;
		i++;
#endif
	}
	revbuf[i] = '\0'; //Imp

	return revbuf; //Imp
}
#endif

#if 0 //Used for Only printing the string in reverse,Here string does not get reversed literally
void func(char *x)
{
	if(*x)
	{
		func(x+1);
                cout<<*x; //This prints the characters in reverse due to stack frames in reverse
	}
}
#endif

int main()
{
	char x[11] ="Global";
	char *rev=func(x);
	cout<<rev<<endl;
}
