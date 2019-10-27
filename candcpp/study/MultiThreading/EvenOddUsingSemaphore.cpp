#include<iostream>
using namespace std;
#include<pthread.h> //Thread,mutex
#include<semaphore.h> //Semaphores
#include <sys/stat.h> //modes
#include<fcntl.h> //O_CREAT
/**********************************************************
Semaphore:Signalling Mechanism
Binary Semaphore: 0,1 states
Counting Semaphore
sem_init(sem_t *s,int pshared,unsigned int value);

1st arg: semaphore variable
2nd arg: whether semaphore is shared b/w different threads(0) of a process or different process(Non-zero)
semaphore shared b/w threads is located at common address (global variable or dynamically allocated variable on heap)
semaphore shared b/w processes is located at shared memory
3rd arg: initial value of semaphore 

NOTE: 
2nd parameter value if 0,thread
              Non-zero,process
3rd parameter value should always be >=1,cannot be 0

Steps:
declare semaphore variable using sem_t
initialize it using sem_init()
sem_wait()  decrements  (locks) the semaphore pointed to by sem.  
If the semaphore's value is greater than zero, then the decrement proceeds, and the function returns, immediately.  
If the semaphore currently has the value zero, then the call blocks until either it becomes possible to perform the decrement (i.e., the semaphore value rises above zero), or a signal handler interrupts the call.

sem_post()  increments (unlocks) the semaphore pointed to by sem. 
This increments the semaphore value(which is already decremented by sem_wait)
If the semaphore's value consequently becomes greater than zero,
then another process or thread blocked in a sem_wait(3) call will be woken up and proceed to lock the semaphore.

sem_destroy()
This destroys the semaphore that has been initialized by sem_init only

All these semaphore Apis return 0, on success
                         return -1, on failure/Error
**********************************************************/

//Even Odd Threads Implementation
//Thread 1 prints Even no's 2,4,6,8,10
//Thread 2 prints Odd no's 1,3,5,7,9

//sem_t s; //declaration of semaphore variable
//sem_init(&s,0,1); //2nd parameter indicates whether the semaphore is for thread or process
                    //if 0,thread
                    //Non-zero,Process

sem_t *s = sem_open("/sm",O_CREAT|O_RDWR,777,2);
int x=0; //Global variable,if u want 0 then make x=0

void* evenFunc(void* msg)
{
	while(x<=10)
	{
                sem_wait(s);
		if(x%2==0)
		{
			cout<<"t1=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
                sem_post(s);
	}
}

void* oddFunc(void* msg)
{
	while(x<=10)
	{
                sem_wait(s);
		if(x%2==1)
		{
			cout<<"t2=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
                sem_post(s);
	}
}

int main()
{
	pthread_t t1,t2;
#if 0
if( sem_init(&s,0,1) < 0 )
{
exit(0);
}
#endif
       //sem_init(&s,0,1); //2nd parameter indicates whether the semaphore is for thread or process
                          //3rd parameter enables the semaphore
	pthread_create(&t1,NULL,evenFunc,NULL);//Pass by reference
	pthread_create(&t2,NULL,oddFunc,NULL);
	pthread_join(t1,NULL); //it is pass by value of thread and has 2nd Argument
	pthread_join(t2,NULL);
        //sem_destroy(&s);
	return 0;
}


