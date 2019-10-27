
/************************************************************************
void *memcpy(void *dest, const void *src, size_t n); 
This copies the memory area of src to dest,so the data also gets copied

NOTE:
Here data can be anything like int,char,struct,class,etc
return type and arguments passed should be void* only

NOTE: typecast is must for void *dest, void *src
************************************************************************/

#include<stdio.h>
#include<string.h>

#if 1
void *func(void* dest, void* src, size_t sz) //return type,arguments data type should be void* only except size_t
{
/* For interger(32bit)
        int32_t *ldest = (int32_t*)dest; 
        int32_t *lsrc = (int32_t*)src;
*/

/* For character(8bit)
        int8_t *ldest = (int8_t*)dest; //int32_t for integer
        int8_t *lsrc = (int8_t*)src;
*/

	char *ldest = (char*)dest;
	char *lsrc = (char*)src;

	while(sz)
	{
		*ldest++ = *lsrc++;
		sz--;
	}
	return dest;
}
#endif

#if 0
//Recursive memcpy
void *recfunc(void* dest, void* src, size_t sz)
{
	char *ldest = (char*)dest;
	char *lsrc = (char*)src;

	if(sz == 0)
		return NULL;

	*ldest = *lsrc;
	recfunc(ldest+1,lsrc+1,sz-1);
}
#endif

int main()
{
	char x[] = "Gesl";
	char y[5] = {'\0'}; //It is Good practice to initialize array elements
	printf("%s\n",(char*)func(y,x,strlen(x))); //Typecasting is must,V.Imp
	//printf("%s\n",(char*)recfunc(y,x,strlen(x)));
        printf("%s\n",y);        
}

