#if 0
volatile:
->Avoid optimization of variables 
->Direct address location instead of going to cache

This keyword tells the compiler not to optimize the code since they get affected by the outside code/external Hardware 
Generally the variables are accessed from cache memory
when we use volatile,the variables are accessed from their address location directly.
Global variables used in ISR[Interrupt Service Routines] get affected, so we should use volatile to avoid it
Global variables used in Multithreaded applications get affected, so we should use volatile to avoid it
#endif

syntax:
volatile int x;

#include<iostream>
using namespace std;

int main()
{
	volatile int x= true;
#if 0
        while(1)
        {
	if(x)
		cout<<"Global\n";
	else
		cout<<"Edge\n";
        }
#endif 
}

*******************************************************************
const:[Read-only]
This variable has to be initialized or else holds garbage value
const int x; //.bss
const int x= 10; //.rodata
const int x =0; //.rodata
We cannot modify this variable,It means we cannot perform any arithmetic operations on it.
It is stored in code/text segment

==========================================================================
Keywords:[SERAM],SSLD 
auto
static
extern
register
mutable[C++]

AERSM
auto //local,stack
extern //global, BSS,data
register //CPU registers
static //BSS,data --file scope,program scope
*******************************************************************
auto:
Default: Garbage value
scope: local scope within the block
storage: stack memory
Life: This variable is alive till the block ends
auto int x; 
 (or)
int x; //By default any variable declared is auto

*******************************************************************
static:[Updated value]
Default: Zero
scope: global scope and local scope based on static variable declaration 
storage:Globally initialized variables,Data segment
storage:Globally un-initialized variables,.bss segment
Life: This variable is alive till the program completes its execution, file scope
NOTE: static takes the latest updated value

Case 1:
static int x; 
cout<<x;// Zero

Case 2:
void func()
{
	for(int i=0;i<3;i++)
	{
		static int x=10;
		x++;
	}
	cout<<x;
}

Case 3:
int func()
{
	static int x=10;
	x++;
	return x;
}

int main()
{
	cout<<func(); //11
	cout<<func(): //12
	cout<<x; //ERROR,Unintialized varible x
}

*******************************************************************
extern: Extending the scope of local variable to global and accessing within multiple files
default value: 0
scope: Global scope within multiple files,Alive till the completion of the program
storage: Globally unitialized segment,.bss in DATA segment
Life: This variable is alive till the program completes its execution
syntax:
extern int x =0;//WARNING
extern int x;//Only Declaration is allowed

NOTE: if int x is not defined in any other file,Linking error occurs 

*******************************************************************
register:[Faster Access in Run time]
Default: Garbage value
scope: local scope within the block
storage: Stored in CPU registers,Faster Access in run time
Life: This variable is alive till the block ends
syntax:
register int x; 

*******************************************************************
mutable: This is used to modify/remove the constantness of const variables
Default: Garbage value
scope: local scope within the block
storage: stack memory
Life: This variable is alive till the block ends

void func() const
{
	mutable int x=0; //This will behave like normal variable say auto
	x++;
	cout<<x;
}

int main()
{
	func();
}

*******************************************************************
Memory Layout: ESHBDRC
Environment variables (or) Command line arguments ,argv[0],argv[1],....
stack -main(),local variables[auto],functions,blocks
Heap -memory allocations,ptr
Globally uninitialized Data[static,extern,normal global variables]-BSS[Block Started by Symbol]
Globally initialized Data[static,extern,normal global variables]
.ro data - constants, V.V.Imp
Code segment/text segment -Read only memory[const]
*******************************************************************
Compilation Steps:[PCAL]
Preprocessing -expanding all Macros,including all headers,disabling the comment lines
Compiling- .i[intermediate code] to .s[Assembly code]
Assembling- .s to .o[Object code]
Linking- .o to .exei

NOTE: isoe
.i -> .s, .s -> .o, .o -> .exe
*******************************************************************
Static linking Libraries[.a]
ar rcs x.o y.o libxx.a 

Dynamic linked libraries/Shared libraries[.so]
gcc -shared -o x.o y.o libxx.so

*******************************************************************







