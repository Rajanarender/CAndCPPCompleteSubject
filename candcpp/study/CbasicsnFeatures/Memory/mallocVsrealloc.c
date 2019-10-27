#include<stdio.h>
#include<stdlib.h>

int main()
{
#if 0 //realloc will take the contiguous memory of malloc, if space is present next to malloc
	//address of ptr remains same for both malloc and realloc
	int *p1 = (int*)malloc(10);
	printf("%p\n",p1);
	p1 = (int*)realloc(p1,120);
	printf("%p\n",p1);
#endif

#if 1 //realloc will not take the contiguous memory of malloc, if space is not present next to malloc  
	//address of ptr remains same for both malloc and realloc
	int *p1 = (int*)malloc(10);
	int *p2 = (int*)malloc(20);//p2 takes the space next to p1 
	printf("%p,%p\n",p1,p2);
	p1 = (int*)realloc(p1,120);
	printf("%p\n",p1);
#endif
}
