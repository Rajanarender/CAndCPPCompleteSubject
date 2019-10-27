#include<stdio.h>
#include<stdlib.h>

/**********************************
Process types:[ODIZ]
Orphan [child live,parent dead]
Daemon
Init
Zombie[child dead,parent sleeping]

Process States:
Ready
Running
Wait/Blocked
Terminated/exit
**********************************/


/***************************************************
Zombie class:
Child process that got exited/terminated and is present in the Process Table
but the exit status of this child process is not known to the Parent process is called as Zombie 
***************************************************/

int main()
{
	pid_t x= fork();
	if(x > 0) //We can write as fork()>0, Parent process
	{
		sleep(10); //V.V.Imp,Mandatory to sleep
#if 0 //infinite loop
                while(1);
#endif
	}
	else if (x==0) //Child process as Zombie
	{
		exit(0); //Child exited
	}
}

//We can avoid Zombie by keeping the parent process in wait state, during this wait state the child process gets all its resources released.
int main()
{
	pid_t x= fork();
	if(x > 0) //We can write as fork()>0, Parent process
	{
		wait(); //V.V.Imp,Mandatory to sleep
	}
	else if (x==0) //Child process as Zombie
	{
		exit(0); //Child exited
	}
}


/***************************************************
Orphan process:
Child process that does not have parent is called as Orphan 
=>Once the Parent process exited/died,the child process is adopted by Init process
=>init process becomes the parent to Orphan process
***************************************************/

int main()
{
	pid_t x= fork();
	if(x > 0) //We can write as fork()>0, Parent process
	{
		exit(0); //Parent exited
	}
	else if (x==0) //Child process
	{
		//sleep(10); //Not necessary to sleep
                printf("In Child process\n");
	}
}

/*****************************************************
Daemon process:
Process that runs in the background

gcc test.c
./a.out & //This exe with & displays the daemon process pid
*****************************************************/

/*****************************************************
Init process:
This is the first starting process and is the parent of all the processes
=>When Any parent process dies, the left child processes are adopted by init process
=>init process is the parent for this Orphan processes
*****************************************************/





