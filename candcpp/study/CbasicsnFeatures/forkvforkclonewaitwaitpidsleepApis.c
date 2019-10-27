Linux system calls:

pid_t fork(void);
pid_t vfork(void); //Both fork and vfork uses clone internally
pid_t clone(int (*fn)(void *), void *child_stack,int flags, void *arg, ...);
pid_t wait(int *status);
pid_t waitpid(pid_t pid,int *status,int options);
unsigned int sleep(unsigned int seconds);
*********************************************************************************
pid_t fork(void) 
Child is created by duplicating the parent
Both the parent and child share different address space,they are independent
They can run parallely

Arguments - No
Return type - pid(>=0) on success,-1 on failure
Ex:
pid_t x = fork();

if(fork() >0)
{
cout<<"parent process\n";
}

*********************************************************************************
pid_t vfork(void) 
Child is created by blocking the parent
Both the parent and child share same address space,they are dependent
Only one process can run at a time

Arguments - No
Return type - pid(>=0) on success,-1 on failure
Ex:
pid_t x = vfork();

if(fork() == 0)
{
cout<<"child process\n";
}
*********************************************************************************
pid_t clone(int (*fn)(void *), void *child_stack,
                 int flags, void *arg, ...);

This creates child process similar to fork() but shares its resource like memory space,file descriptors,etc with the Parent[calling] process

NOTE:
Both fork,vfork internally calls clone
*********************************************************************************
pid_t wait(int *status)
This suspends the execution of calling process and allows the execution of any ONE of its childs
Once the child gets terminated, the calling process gets resumed/continues

Arguments - status with reference
Return type - pid(>=0) on success,-1 on failure

Ex:
pid_t x =wait(&status);
wait(NULL);

*********************************************************************************
pid_t waitpid(pid_t pid,int *status,int options)
This suspends the execution of calling process and allows the execution of child whose pid is passed as argument
Once the child gets terminated, the calling process gets resumed/continues

NOTE:
waitpid(-1,&status,0) is equal to  wait(&status)
if pid passed into waitpid() >0, then pid passed = pid returned

Ex:
pid_t x= waitpid(1,&status,0);
cout<<x; //1

x= waitpid(2,&status,0);
cout<<x; //2

x =waitpid(2256,&status,0);
cout<<x; //2256

x= waitpid(-2,&status,0);
cout<<x; 

x= waitpid(-1,&status,0); //wait(&status)
cout<<x; 

x= waitpid(0,&status,0);
cout<<x; 

*********************************************************************************
unsigned int sleep(unsigned int seconds);
This makes the calling process to delay/sleep for xsecs

Ex:
sleep(5); //5secs

*********************************************************************************
exec API's:
int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);

The above exec functions replace the current process image with new process image
