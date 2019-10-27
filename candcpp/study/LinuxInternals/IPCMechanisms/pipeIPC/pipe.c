#include<stdio.h>
#include<unistd.h> //Header included for pipe,sleep()

int main()
{
	char msgtxt[7]="GLOBAL";
	int fd[2];
	pipe(fd);

	int ret = fork();
	if(ret>0) //Parent Process(ret>0) Writes the data
	{
		printf("I am the Parent Process\n");
                //printf("Enter the Data:\n");
                //scanf("%s",msgtxt);
		write(fd[1],msgtxt,sizeof(msgtxt));
	}

	if(ret == 0) //Child Process(ret == 0) Reads the data
	{
		sleep(2);
		printf("\nI am the Child Process\n");
		read(fd[0],msgtxt,sizeof(msgtxt));
		printf("%s",msgtxt);
	}
}
