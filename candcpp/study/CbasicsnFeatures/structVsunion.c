#include<stdio.h>

/***************************************************
struct:
=>sizeof(struct) greater than[We can decrease it by using #pragma pack(1)] or equal to sum of all data members
=>Each member will have different memory space 
=>Changing the value of member will not affect the other
=>All the members can be accessed and modified at the same time
NOTE: To avoid struct padding,we use preprocessor directive #pragma pack(1)

union:
=>sizeof(union) is equal to the largest data type
=>All the data members will share the same/common memory space V.V.Imp
=>Changing the value of member will affect the other
=>Only one member can be accessed/modified at a time V.V.Imp
***************************************************/

struct X
{
	char a;
	int b;
};

union Y
{
	char c;
	int d;
};

int main()
{
	struct X obj;
	printf("%lu \n",sizeof(obj) ); //8bytes
	obj.a='d';
	obj.b=10;
	printf("%c %d\n",obj.a,obj.b);

	union Y obj1;
	printf("%lu \n",sizeof(obj1) ); //4bytes
	obj1.c='e';
	obj1.d=20;
	printf("%c\n",obj1.c);
	printf("%d\n",obj1.d);
}
