#include<stdio.h>

/**********************************************************************************
func names with different names are created due to Name Mangling in C++

 -E                       Preprocess only; do not compile, assemble or link
 -S                       Compile only; do not assemble or link
 -c                       Compile and assemble, but do not link
 -o <file>                Place the output into <file>

g++ -E NameMangling.cc 
g++ -S NameMangling.cc //This wil generate NameMangling.s

Execute these commands: 
g++ -c NameMangling.cc //This wil generate NameMangling.o 
nm NameMangling.o

o/p:
0000000000000033 T main
                 U printf
0000000000000016 T _Z4funci //func(int x)
0000000000000000 T _Z4funcv //func() 
Both functions have their own names

NOTE:use only printf statements to generate this NameMangling
DO NOT use cin,cout

Overloading is present in C++, due to Name Mangling
C Doesnt have Name Mangling, So throws Error "Redefinition of func"
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
