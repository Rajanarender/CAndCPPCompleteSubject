#include<stdio.h>

typedef struct _Base
{
	int *ptr;
	int (*fptr)(int); //function ptr declaration

#if 0 //We cannot declare function within struct
        int func(int m); 
#endif

}X;

int func(int m)
{
	return m*m;
}


int main()
{
	X obj;
	int k =10;
	obj.ptr = &k;
	obj.fptr=func; //function ptr assignation
	printf("%d\n",obj.fptr(5));
}


