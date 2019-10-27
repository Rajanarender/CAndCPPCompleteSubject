#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch='\010';
	printf("%d\n",ch); //8

	unsigned int a =-1;
	printf("%d\n",a); //-1
#if 0
	char buf[5];
	int a =25;
	itoa(a,buf,2);
	printf("%s",buf);
#endif
}

