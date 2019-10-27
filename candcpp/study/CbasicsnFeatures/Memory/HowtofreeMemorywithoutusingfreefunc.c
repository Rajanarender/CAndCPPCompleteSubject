#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p = (int*)malloc(sizeof(int));
	//free(p);
	(int*)realloc(p,0); //Instead of free(), we can use realloc() with 0 bytes
	if(*p == '\0')
	{
		printf("Memory is freed\n");
	}
}
