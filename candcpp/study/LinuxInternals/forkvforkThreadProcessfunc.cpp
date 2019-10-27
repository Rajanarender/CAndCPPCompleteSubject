fork()
=>Parent and child processes have different address spaces
=>Due to different address spaces, they can execute simulataneously
=>uses copy-on-write

vfork()
=>Parent and child processes share same address space
=>Due to same address spaces, only one process can execute at a time with the other remaining in suspended state
=>Does not use copy-on-write


Thread
Creation:pthread_create() API
Contextswitching: b/w states[read/write] is faster
Communication:Threads can communicate internally, no need of any ITC mechanism
Corruption:If one thread gets corrupted, then remaining all threads get corrupted
Execution:

Process
Creation:fork(),vfork() API
Contextswitching: b/w states[read/write] is slower
Communication:Processes cannot communicate internally, need IPC mechanisms[shm,msg,pipe,fifo]
Corruption:If one process gets corrupted,it will not impact other processes since one process is invisible to the other
Execution:
