
/***************************************************************************************************
if we use c related library apis in C++ code directly without C headers will result in linking error
because compiler does Name Mangling(separate Names)
TO avoid it, use extern "C" so that no Name Mangling and compiler gets the api def from extern "C" 
***************************************************************************************************/

#if 0
#include<stdio.h>


int main()
{
	printf("Gesl\n");
}

#endif

#if 1
//int printf(const char* format...); //Linking Error

//Solution
extern "C" 
{ 
	int printf(const char* format...);
}


int main()
{
	printf("Gesl\n");
}

#endif
