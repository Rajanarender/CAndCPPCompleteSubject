*******************************************************************
malloc vs new
malloc:
char x[]="Global Edge";
char*p=(char*)malloc(sizeof(char)*(strlen(x)+1) );
=>This is  a function,typecasting is must
if malloc is success,returns valid ptr 
if malloc is fail,returns NULL ptr
=>It cannot initialize the memory,where calloc can do
=>We cannot overload it
=>It cannot call constructor and destructor
=>Memory deallocation is done using free() function

new:
char x[]="Global Edge";
char *p = new char[strlen(x)+1]; //1byte for '\0' character
=>This is a operator,no need of typecasting
=>It initializes the memory
=>We can overload new operator
=>It calls the constructor and delete calls destructor
=>Memory deallocation is done using delete

*******************************************************************

