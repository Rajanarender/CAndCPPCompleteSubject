
/************************************************************************
void *memset(void *dest, int n, size_t sz); 
This fills the first n bytes of memory area of dest with specified sz bytes

NOTE:
Here data can be anything like int,char,struct,class,etc
return type and arguments passed should be void*, int, size_t

NOTE: typecast is must for dest 
************************************************************************/

#include<iostream>
using namespace std;
#include<string.h>
#include<cstdint>

#if 1
void *func(void* dest, int n, size_t sz) //return type,arguments data type should be void* only except size_t
{
/* For interger(32bit)
        int32_t *ldest = (int32_t*)dest; 
*/

/* For character(8bit)
        int8_t *ldest = (int8_t*)dest; //int32_t for integer
*/

	char *ldest = (char*)dest; //Typecast is must
	char *temp = ldest;
	while(sz)
	{
		*ldest++ = n;
		sz--;
	}
	return temp;
}
#endif

#if 0
//Recursive memcpy
void *recfunc(void* dest, int n, size_t sz)
{
	char *ldest = (char*)dest;

	if(sz == 0)
		return NULL;

	*ldest = n;
	recfunc(ldest+1,n,sz-1);
}
#endif

int main()
{
	char x[] = "Gesl";
	printf("%s",(char*)func(x,10,strlen(x))); //typecasting is must
	printf("%s",recfunc(x,10,strlen(x)));
	cout<<x<<endl;
}

