#include<stdio.h> //for printf
#include<unistd.h>
#include<fcntl.h> //for O_RDONLY

int main()
{
	char msgtxt[7];
	int fd = open("/tmp/myfifo",O_RDONLY);
	read(fd,msgtxt,sizeof(msgtxt));
        //write(1,msgtxt,sizeof(msgtxt));
	printf("%s\n",msgtxt);
        close(fd);
}
