#include<iostream>
using namespace std;
#include<string.h>

class String
{
	char *s;
	int l;

	public:
	String()
	{
		l=0;
		//s=new char[11]; s3 gets memory alloc in Operator overloading,so no need in Constructor again
	}

	~String()
	{
		delete [] s;
	}

	String(char *p)
	{
		l=strlen(p);
		s=new char[l+1];
		strcpy(s,p);
	}

#if 0 //Not needed, since we are not copying object to object
	String(const String &obj)
	{
                //l = strlen(obj.s);
		l=obj.l;
		s=new char[l+1];
		strcpy(s,obj.s);
	}
#endif
	String& operator+(const String &obj) //operator must be + , not =
	{
		if(this != &obj)
		{
			String *temp; //Taking 3rd variable
			temp->l = this->l+obj.l;
                        temp->s= new char[temp->l+1];
#if 0 //This is Wrong,this should not get affected 
                        strcat(this->s,obj.s); //this is getting changed here
                        strcpy(temp->s,this->s);
#endif
#if 1 //V.V.Imp
			strcpy(temp->s,this->s); //Copy string of this into temp 
			strcat(temp->s,obj.s);//concatenate string present in temp with string in obj
#endif
			return *temp; 
		}
	}

	void display()
	{
		cout<<s<<endl;
	}    
};

int main()
{
        char x[] = "Global";
        char y[] = "Edge";
	//String s1("Global"),s2("Edge"),s3;
	String s1(x),s2(y),s3;
	s3=s1+s2; //s1 should not be affected at any cost
	s1.display();
	s2.display();
	s3.display();
}
