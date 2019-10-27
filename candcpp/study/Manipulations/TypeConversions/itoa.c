#include<stdio.h>
#include<string.h>
#include<stdlib.h> //for itoa()

/********************************************************************************
convert integer to decimal(10),binary(2),octal(8),hexadecimal(16) Arrayformat
itoa(number,o/pstoragebuf,Arrayformat);
*********************************************************************************/

void func(int num,char *buf,int b)
{
	char* localbuf =buf;//Preserve the buf to localbuf,V.V.Imp step

	int rem=0;
	while(num)
	{
		rem = num%b; //Only remainder is needed to buf
		if(rem >=10 && rem <=15) //Hexadecimal format check
		{
			*buf = rem+55; //10+55 ='A',11+55 ='B',12+55 ='C',13+55 ='D',14+55 ='E',15+55 ='F'
		}
		else //Storing only remainder into buffer
		{
			*buf = rem +'0';//(Adding ASCII value)
		}

		buf++;
		num = num/b; //For traversing thru number using only quotient
	}
	*buf = '\0'; //V.V.Important step

	buf= localbuf; //Now buf points to its Base Address,V.V.Imp step

#if 0 //Since this API doesnot work in this linux system, use the code below
	strrev(buf);    
#endif
	char *start =buf; //Reverse the base
	char *end=buf+strlen(buf)-1;
	while(start<end) //only addresses
	{
//Swap the elements
		char temp = *start;
		*start=*end;
		*end=temp;

		start++;
		end--;
	}
}

int main()
{
	char buf[1024];
	//itoa(172,buf,16); // Convert integer to array or string
	func(172,buf,16); //base like 10,2,8,16
	printf("%s\n",buf);
}
