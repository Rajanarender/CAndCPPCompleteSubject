#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

 /*******************************************************************************
Linux command: ipcs -q [This is the 2nd name in IPC like message queue]
This command displays All Shared Memory Segments with details like 
key(Hexadecimal format),msqid,owner,Permissions,Message Queue(in Bytes),messages,etc
*********************************************************************************/
 
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
	msgid = msgget(key, 0666 | IPC_CREAT); //666-Read,Write - Owner,group,others
                                               //777-Read,Write,Execute - Owner,group,others
                                               //444-Read,Read,Read
                                               //222-Write,Write,Write
                                               //111-Execute,Execute,Execute

//Before sending the message,Fill the msg_buffer,V.V.Imp 
	message.mesg_type = 1;
	printf("Write Data : ");
	gets(message.mesg_text);

	// msgsnd to send message
	msgsnd(msgid, &message, sizeof(message), 0); //sending message with reference,V.V.Imp

	// display the message
	printf("Data send is : %s \n", message.mesg_text);

	return 0;
}
