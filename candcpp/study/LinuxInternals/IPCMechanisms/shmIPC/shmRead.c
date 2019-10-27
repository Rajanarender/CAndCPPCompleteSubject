#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
	// ftok to generate unique key
	key_t key = ftok("shmfile",65);

	// shmget returns an identifier in shmid
	int shmid = shmget(1,1024,0666|IPC_CREAT);

	// shmat to attach to shared memory
	char *str = (char*) shmat(shmid,(void*)0,0); //V.V.Imp, 1st attach the memory by typecasting and then fill the message

	printf("Data read from memory: %s\n",str);

	//detach from shared memory 
	shmdt(str);

	// destroy the shared memory
	shmctl(shmid,IPC_RMID,NULL);

	return 0;
}
