
//Use this linux command to display the memory space occupied by these variables: objdump -x a.out

/* Note : Global variables with initialised to zero or un-initialised will store in .bss section */ V.V.Imp


/****************************************************
All these global variables are stored in .bss
int x;//int x=0
static int x; //static int x=0
const int x;
const int x=0; //.rodata
const static int x;
const static int x=0; //.rodata
****************************************************/

#include<stdio.h>

int l;         // Uninitialized data section (.bss)
int k = 0;    // Uninitialized data section (.bss)

int m = 1;    // Initialized data section (.data)

static int n; //same as int n=0 // Uninitialized data section (.bss)
static int n1 =0; //same as int n=0 // Uninitialized data section (.bss)
static int o = 1; // Initialized data section (.data)

const int p;     // Uninitialized data section (.bss)
const int p1 = 0;     // Initialized data section (.rodata)
const int q = 1 ;  // Initialized data section (.rodata)

const static int r;  // Uninitialized data section (.bss)
const static int r1=0;  //Initialized data section (.rodata)
const static int s = 1;  // V.Imp, Initialized data section (.rodata)


//NOTE: In function all the variables are stored in Stack except static variables
//Stack variables storage is done at RUN time, so we cannot check using linux commands

int main (void)
{
        printf("%d",l); // global unitialized variables will hold default value 0

        int a;                    // stack
        int b = 0;                // stack
        int b1 = 10;       

        static int c;  // Uninitialized data section (.bss)
        static int d = 1; // Initialized data section (.data)

        const int e;          // stack
        const int f = 0;      //Initialized data section (.rodata)
        const static int g;  // Uninitialized data section (.rodata)

        const static int h = 1;  //V.Imp,Initialized data section (.rodata)

        return 0;
}

