#include<iostream>
using namespace std;
#include<stdlib.h> //for exit(),_Exit()
#include<unistd.h> //for _exit()
 
/************************************************
void exit(int status);

exit();//Does not reveal what type of termination it is?
exit(0);It means successful termination
exit(1); It means abnormal termination
************************************************/
#if 0
void func()
{
	int x=0;
	while(x<5)
	{
		cout<<x<<endl;
		x++;
		if(x==4)
			exit(0);
	}
}

int main()
{
	func();
	cout<<"In main()"<<endl;
}
#endif

/**********************************************
exit()-This is normal termination
_exit() (or) _Exit() -terminates the calling process
**********************************************/
#if 0
int main()
{
	cout<< "In main()\n";
	exit(0);
}
#endif

#if 1
int main()
{
	cout<< "In main()\n";
	//_Exit(10); //present in stdlib.h
	_exit(10); //present in unistd.h
}
#endif




