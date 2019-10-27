#include<iostream>
using namespace std;


void func(char *d, const char *s)
{
        if(s == NULL) //corner case
        return;

	if(*s == '\0') //base condition
	{
		*d='\0';
		return;
	}

	*d=*s;
	func(d+1,s+1);

}

int main()
{
	char src[]="Gesl";
	char des[5];
	func(des,src);
        //func(des,NULL);
        cout<<des<<endl;
}
