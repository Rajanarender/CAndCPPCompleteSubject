#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h> //for struct sockaddr_in

/**********************************************************************************
gcc client.c -o client.out
CLI:./client.out hostipaddress portno
socket();

#if 0 //No need of these things
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY; //IP address 
portno = atoi(argv[2]); //portno from char array to integer format ,V.V.Imp step
serv_addr.sin_port = htons(portno); //portno from integer to N/w format 
#endif 

sendto()=write()+connect() //6 arguments
recvfrom()=read()+connect() //6 argumens
read();
write();
***************************************************************************************/

int main(int argc,char* argv[])
{
	int sockfd,portno;
        char buff[256];
	struct sockaddr_in serv_addr,cli_addr;

	if(argc <3) //argv[0]=./a.out, argv[1]=hostaddress[say 192.168.20.105], argv[2]=portno[say 1234]
	{
         //fprintf(stderr,"ERROR since no portno provided in client Commandline\n");
          perror("ERROR since no portno provided in client Commandline\n");
          exit(1);
	}

	sockfd = socket(AF_INET,SOCK_DGRAM,0); //DGRAM
	if(sockfd<0)
	{
             perror("ERROR in creating socket\n");
             exit(1);
	}

#if 0 //This is not needed in UDP as we dont have connect() API
//Fill the sockaddr_in structure using serv_addr object before connecting client to serv_addr
        serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY; //IP address 
	portno = atoi(argv[2]); //portno from char array to integer format ,V.V.Imp step
	serv_addr.sin_port = htons(portno); //portno from integer to N/w format 
#endif

	int n;
	n = sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr)); //sendto()=write()+connect()
		if(n<0)
		{
			perror("ERROR in sendto");
			exit(1);
		}

	n = recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr)); //recvfrom()=read()+connect()
		if(n<0)
		{
			perror("ERROR in recvfrom");
			exit(1);
		}

               write(1,"Got an ack",12);
}




