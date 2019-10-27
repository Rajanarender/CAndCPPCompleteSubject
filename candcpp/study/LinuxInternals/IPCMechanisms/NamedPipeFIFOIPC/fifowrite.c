#include<unistd.h>
#include<fcntl.h> //for O_WRONLY

/************************************************
Communcation b/w 2 different,irrelavant processes using file system
Writer does not complete its execution unless reader completely reads the data

NOTE: The fifo filename should be same at both writing & reading side
************************************************/
int main()
{
	mkfifo("/tmp/myfifo",0666);
	int fd = open("/tmp/myfifo",O_WRONLY);
	char msgtxt[7]="GLOBAL";
	write(fd,msgtxt,sizeof(msgtxt));
	close(fd);
}
