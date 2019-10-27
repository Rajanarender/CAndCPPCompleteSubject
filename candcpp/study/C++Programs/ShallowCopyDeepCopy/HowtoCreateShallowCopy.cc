#include<iostream>
using namespace std;
#include<string.h>

/*********************************************************************************
The below scenario is Shallow Copy
If we enable new in constructor and delete in destructor, it is called Deep Copy
*********************************************************************************/

#if 1 //Shallow Deep Copy in c++ language
class Base
{
	public:
		char *s;
		Base(const char *x)
		{
			//s=new char[strlen(x)+1];
			strcpy(s,x);
		}

		void display()
		{
			cout<<s<<endl;
		}

#if 0          
                ~Base() //Destructor is Mandatory for generating segmentation fault
                {
                  delete []s;
                }
#endif
};

int main()
{
	Base b("Gesl"),c=b; 
        b.display();
        c.display();
}
#endif

#if 0 //Shallow Deep Copy in c language
#include<stdlib.h> //malloc()
char* func(const char *x)
{
	char *s;
	s=(char*)malloc((sizeof(char) * (strlen(x)+1) ); //Mandatory
	//s=new char[strlen(x)+1];
        strcpy(s,x);
	return s;
}

int main()
{
	cout<<func("Gesl")<<endl;
}
#endif








