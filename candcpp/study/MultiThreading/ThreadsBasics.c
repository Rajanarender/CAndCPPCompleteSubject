#include<stdio.h>
#include<pthread.h>

/**********************************************
Thread:
pthread_create() has 4 arguments only
function name with Single argument can only be passed
If we want to pass multiple parameters of func in pthread_create(), 
then collect this parameters into a struct,create a ptr of this struct and pass it to pthread_create()

Array of threads:
pthread_t t[2];

for(int i=0;i<2;i++)
{
pthread_create(&t[i],NULL,func,NULL);
}
------------------------------------
Passing integer value:
void *func(void *arg)
{
int m = *((int*)arg); //V.V.Imp step, Always type cast void to other data type while dereferencing
}

int x=10; 
pthread_create(&tid,NULL,func,&x); //Always pass reference of func parameter
(or)
pthread_create(&tid,NULL,func,(void*)&x); //Always pass reference of func parameter

---------------------------------------
Passing string Array:
void *func(void *arg)
{
char* m = (char*)arg;
}

char x[]="Global"; 
pthread_create(&tid,NULL,func,x);

Passing integer Array: //TBD
void *func(void *arg)
{
int m[0] = *((int*)arg);
}

int x[]={2,4,6}; 
pthread_create(&tid,NULL,func,x);

----------------------------------------
Passing pointer:
void *func(void *arg)
{
int m = *(int*)arg;
}

int m=10;
int *x=&m; 
pthread_create(&tid,NULL,func,x);
*******************************************/

void *func0(void* arg) // passed arg is char*
{
	   char *y=(char*)arg;
	   printf("%c\n",*y);
}

void *func1(void* arg) //Here only one argument is allowed
{
        int y[3];
	y[0]=*((int*)arg);
        y[1] = *((int*)(arg+1));
        y[2] = *((int*)(arg+2));
}

void *func2(void* arg) // passed arg is char y[]
{
	   char *y=(char*)arg;
	   printf("%s\n",y);
}

void *func3(void* arg) // passed arg is  int 
{
	   int y=*((int*)arg);
	   printf("%d\n",y);
}

typedef struct _st
{
int i;
char j;
}St;

void *func4(void* arg) //Here only one argument is allowed
{
	   St *y = (St*)arg; //casting to local struct
	   printf("%d\n",y->i);
           printf("%c\n",y->j);
}

int main()
{
	pthread_t t1,t2,t3,t4;
/*
        char l ='Z'; //TBD
	char *w =&l;
        pthread_create(&t0,NULL,func0,w);//passing pointer
*/
 
        int x[]={2,4,6}; //TBD
	pthread_create(&t1,NULL,func1,x);//passing int array

	char y[]="Hi";
	pthread_create(&t2,NULL,func2,y);//passing string

	int z =10;
	pthread_create(&t3,NULL,func3,&z); //Passing int

        St *obj;
        obj->i=100;
        obj->j='X';
	pthread_create(&t4,NULL,func4,obj); //Passing multiple arguments of func using struct

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
}



