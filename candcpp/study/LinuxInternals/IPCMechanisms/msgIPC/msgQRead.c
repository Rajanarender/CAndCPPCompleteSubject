#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
 
// structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;

int main()
{
	key_t key;
	int msgid;

	// ftok to generate unique key
	key = ftok("progfile", 65);

	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key,IPC_CREAT);

for(;;) //Receiver should keep on listening,V.V.Imp
{
	// msgrcv to receive message
	if(msgrcv(msgid, &message, sizeof(message), 1, 0)==-1) //message with reference,V.V.Imp
          perror("msgrcv");
}
	// display the message
	printf("Data Received is : %s \n", 
			message.mesg_text);

	// to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}
