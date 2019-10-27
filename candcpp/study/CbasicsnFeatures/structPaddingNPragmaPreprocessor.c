#include<stdio.h>

/**********************************************************
struct padding:
When we have data members in the structure, empty bytes[called as HOLES] exists b/w data members memory.Due to this memory gets wasted
Due to struct padding memory gets wasted and the size of structure will not be same as we expect. 

Solution:
Solution1:
=> Use macro pragma pack preprocessor directive
#pragma pack(1)
This removes all the holes completely

Solution2:
=>We can align the data members in the multiples of their size
char[multiples of 1]   1,2,3,..
short[multiples of 2]  2,4,6,8,...
int[multiples of 4]    4,8,12,..
This does not remove all the holes,few holes will be still existing

Solution1 is more preferable

FYI: 
The processor[32bit] reads only 1word=4bytes at a time
The processor[64bit] reads only 1word=8bytes at a time
**********************************************************/

#if 1
#pragma pack(1) //Macro used for avoiding struct padding
struct x //Data members can be in any position
{
	char a;
	char b;
	int d;
	char c;
};

int main()
{
	printf("%lu\n",sizeof(struct x)); //7bytes
}
#endif

#if 0
#pragma pack(1)
struct x
{
	char a;
	char b;
	char c;
	int d;
};

int main()
{
	printf("%lu\n",sizeof(struct x));
}

struct x
{
	char a;
	char b;
	char c;
	int d;
};

int main()
{
	printf("%lu\n",sizeof(struct x));
}

#endif

