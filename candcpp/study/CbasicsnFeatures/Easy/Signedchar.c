#include<stdio.h>

/********************************************************
signed char/default type - [-128 to 127] i.e., [-128 to -1,0 to 127]
unsigned char - [0 to 255]

NOTE:
=>char x= any value b/w -128 to 127,will print the same 
=>char x = any value b/w 128 to 255, will print -128 to -1,V.V.Imp
********************************************************/

int main()
{
	char x=-128; //default signed, not necessary to write as signed
        //signed char x = -128;
	printf("%d\n",x); //-128

	x=-127;
	printf("%d\n",x); //-127

	x=-1;
	printf("%d\n",x); //-1

        x=0;
	printf("%d\n",x); //0

	x=1;
	printf("%d\n",x); //1

	x =127; //default signed
	printf("%d\n",x); //127

	x=128;
	printf("%d\n",x); //-128

	x=129;
	printf("%d\n",x); //-127

	x=254;
	printf("%d\n",x); //-2

	x=255;
	printf("%d\n",x); //-1

#if 0
	x=256; //Error,Accepts only 0 to 255 
	printf("%d\n",x);

	x=-129; //Error,Accepts only -128 to -1
	printf("%d\n",x);
#endif
}
