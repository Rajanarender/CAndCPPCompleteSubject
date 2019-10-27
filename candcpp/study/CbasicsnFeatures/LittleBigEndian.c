#include<stdio.h>

/*************************************
What is Little Endian?Big Endian?
How to Convert Little to Big Endian?
Code for knowing/getting the Endianness of a machine?

int num = 0x12345678
Big Endian:[All PC's,laptops used by us are in this format only]
MSB is 12,LSB is 78
MSB is stored at lower address,
LSB is stored at higher address,
num will be in this format 12 34 56 78 

Little Endian:
MSB is 12,LSB is 78
MSB is stored at higher address,
LSB is stored at lower address,
num will be in this format  78 56 34 12 

lscpu -linux command to know th Endianness of machine
**************************************/

int main()
{
#if 0
	int x = 0x12345678;
	char c =(char)x;
	printf("%x\n",c);
	if(c==0x78)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
#endif
#if 1
	int x = 1;
	char *c =(char*)&x;
	if(*c)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
#endif

}
