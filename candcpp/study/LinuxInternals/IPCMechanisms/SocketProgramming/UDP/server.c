#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h> //for struct sockaddr_in

/**********************************************************************************
gcc server.c -o server.out
CLI:./server.out portno
socket();

serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY; //IP address 
portno = atoi(argv[1]); //portno from char array to integer format ,V.V.Imp step
serv_addr.sin_port = htons(portno); //portno from integer to N/w format

V.V.Imp
sendto() = write()+accept() //6 arguments
recvfrom() = read()+accept() //6 argumens
read();
write();
***************************************************************************************/


int main(int argc,char*argv[])
{
	int sockfd,portno;
	char buff[256]; //Buffer to store data
	struct sockaddr_in serv_addr,cli_addr; //2 struct objects client and server

	if(argc < 2) //argv[0]=./server.out,argv[1]= portno[say 1234]
	{
		//fprintf(stderr,"ERROR since no portno provided in server Commandline\n");
		perror("ERROR since no portno provided in server Commandline\n");
		exit(1);
	}

	sockfd = socket(AF_INET,SOCK_DGRAM,0); //SOCK_DGRAM
	if(sockfd<0)
	{
		perror("ERROR in creating socket\n");
		exit(1);
	}

#if 1 //The loading of socket parameters should be same as client
	//Fill the sockaddr_in struct using serv_addr object before binding serv_addr with socket
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY; //IP address 
	portno = atoi(argv[1]);//portno from char array to integer format
	serv_addr.sin_port = htons(portno);//portno from host byte to N/w byte of unsigned short int format 
#endif

	if ( bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0 ) //bind server_addr to socket
	{
		perror("ERROR in binding socket\n");
		exit(1);
	}

        int clilen;  
	int n;
	while(1)
	{
		n = recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&cli_addr,&clilen); //recvfrom() = read()+accept()
		if(n<0)
		{
			perror("ERROR in recvfrom");
			exit(1);
		}

		write(1,"Received a Datagram",21);

		n = sendto(sockfd,"Got client Mesage",17,0,(struct sockaddr*)&cli_addr,&clilen); //sendto() = write()+accept()
		if(n<0)
		{
			perror("ERROR in sendto");
			exit(1);
		}
	}
}







