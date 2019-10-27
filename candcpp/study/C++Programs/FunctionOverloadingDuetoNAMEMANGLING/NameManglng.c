#include<stdio.h>

/**********************************************************************************
 -E                       Preprocess only; do not compile, assemble or link
 -S                       Compile only; do not assemble or link
 -c                       Compile and assemble, but do not link
 -o <file>                Place the output into <file>

gcc NameManglng.c //error: redefinition of ‘func’
***********************************************************************************/

void func()
{
	printf("int argument");
}

void func(int x)
{
	printf("char argument");
}

int main()
{
	func();
        func(10);
}
