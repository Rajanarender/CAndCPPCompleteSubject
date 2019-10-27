#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*****************************************************************************************
malloc()
=>Memory is not initialised to zero(Holds Garbage value)
=>Memory is present in contiguous memory
NOTE: Need to use memset after malloc(),to initialize the memory to zero
syntax:
void *malloc(size_t size);

calloc()
=>Memory is initialised to zero
=>Memory is present in non-contiguous memory
syntax:
void *calloc(size_t items,size_t size);

realloc()
=>Adding Extra memory bytes to that existing bytes allocated by malloc(),calloc()
=>It resizes the same memory of the block that was initially allocated using malloc() or calloc()
=>It does not create new memory separately but uses the same memory of the old block
=>returns the same ptr address as that of malloc

syntax:
void* realloc(void* ptr,size_t size);

free()
=>It releases the memory ,that was used by malloc(),realloc(),calloc()
void free(void* ptr); //return type of free is void not void*,V.V.Imp
**********************************************************************************************/


int main()
{
	char *x;
	x=(char*)malloc(sizeof(char)*7);
        x=(char*)calloc(7,sizeof(char)); //calloc() API
	if(x==NULL)
	{
		printf("Sufficient Memory is not Present on RAM\n");
	}
	else
	{
		strcpy(x,"Global");
		x=(char*)realloc(x,sizeof(char)*11); //Existing data is not disturbed and new data will be added to that
		strcat(x,"Edge");
		printf("%s\n",x); //GlobalEdge

		x=(char*)malloc(sizeof(char)*11); //Bytes get overridden due to which data is lost
		strcat(x,"Edge"); 
		printf("%s\n",x); //Edge
	}
}
