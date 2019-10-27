#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/******************************************
=>calculate the length of the source 
=>Allocate that many bytes+1 to the destination
=>Now copy the source to destination
******************************************/

char* func(const char* x)
{
#if 0 //Shallow copy, this leads to Segmentation fault
        char *y;
        strcpy(y,x);
#endif

#if 1 //Deep copy
        int l =strlen(x);
	char *y=(char*)malloc( (l+1)*sizeof(char) ); //Need to check whether this memory gets freed automatically
	strcpy(y,x);
#endif

	return y;
}


int main()
{
	//printf("%s",func("Global"));
	char *m=func("Global");
	printf("%s",m);
}
