
void ptr:
int k = 100;
int *x = &k;
void *m = x; //void ptr is a type,it can directly point to ptr of any data type
cout<<(int*)m; // It is Mandatory to typecast void type when dereferencing, or else we get ERROR


wild ptr: 
This ptr does not hold any address
int *x;
x = &y;

NULL ptr:
This ptr hold address with no value
int *x = NULL; 
char *y = '\0';

Dangling ptr:
Ptr pointing to deleted memory

Segmentation fault:
Trying to dereference wild,NULL,dangling ptr
Recursive functions
Array out of Boundary access

const ptr:
int y = 10;
int* const x = &y; //pointer pointing to const address, we cannot change address
x= &z; //ERROR

ptr to const:
const int y =10; //This should be const
const int *x = &y;
 (or)
int const *x =&y;
x= &z; //Works fine
y= 20; //ERROR

Double ptr:
int **y; 
(or)
int*y[];

Ptr to Array;

Array of ptrs:


Ptr to func: //function ptr is used for callback functions

*this ptr:

virtual ptr: //vptr











