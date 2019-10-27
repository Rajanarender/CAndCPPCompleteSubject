#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include<stdlib.h>

/*******************************************************************************
Linux command: ipcs -m [This is the 2nd name in IPC like shared memory]
This command displays All Shared Memory Segments with details like 
key(Hexadecimal format),shmid,owner,Permissions,shared memory size(in Bytes),etc
*********************************************************************************/
 
int main()
{
	// ftok to generate unique key
	key_t key = ftok("shmfile",65);

	// shmget returns an identifier in shmid
	int shmid = shmget(key,1024,0666|IPC_CREAT); 

	// shmat to attach to shared memory
	char *str = (char*) shmat(shmid,(void*)0,0); //V.V.Imp, 1st attach the memory by typecasting and then get the message

	printf("Write Data : ");
	gets(str);

	printf("Data written in memory: %s\n",str);

	//detach from shared memory 
	shmdt(str);//V.V.Imp,detach by message only and not shmid
	return 0;
}
