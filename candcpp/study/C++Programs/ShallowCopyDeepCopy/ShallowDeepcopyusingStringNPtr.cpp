#include<iostream>
using namespace std;
#include<string.h>

//NOTE: Always Do Deep Copy in constructor,copy constructor,Assignment operator
//To avoid Dangling ptr,which in turn leads to Segmentation Fault

/**********************************************************************
Shallow copy, Deep copy using String,pointer(int,char)
***********************************************************************/
#if 1
class String
{
	int l;
	char *s;

	public:
	String()
	{
		l=0;
		//s=new char[8]; s3 object gets memory allocation in Assignment operator,so no need here
	}

	~String() //This releases the memory allocated in Param cons,Copy cons,Assignment operator
	{
		delete [] s;
	}

	String(char *p) //This is same as copying the passed argument to local ptr                         
	{
		l=strlen(p);
		s = new char[l+1];//Deep Copy
		//s = new char[strlen(p)+1];
		strcpy(s,p);
	}

	String(const String &obj)
	{
		l=obj.l;
		s = new char[l+1];
                //s = new char[obj.l+1];
		strcpy(s,obj.s);
	}

	String& operator=(const String &obj)
	{
		if(this != &obj) //Self Assignment Check Condition
		{

#if 0 //This will modify the destination object
			this->l=obj.l;
			this->s = new char[this->l+1];
			strcpy(this->s,obj.s);
#endif
			String *temp; //Always use temporary class object
			temp->l=obj.l;
			temp->s = new char[temp->l+1];
			strcpy(temp->s,obj.s);
			return *temp; //Imp
		}
#if 0
		return *this;
#endif
	}

	void display()
	{
		cout<<s<<endl;
	}

};

int main()
{
        char x[] = "Global";
        //char *x = new char;
	String s1(x),s2=s1,s3;
	//s3=s2;
        s3.operator=(s2); //We can write in this way also
	s1.display();
	s2.display();
	s3.display();
        //delete x; //if new is used
	return 0;
}
#endif

/*********************************
Case 1: Ptr is char/int type
**********************************/
#if 0
class Ptr
{

	char *s;
	public:
	Ptr()
	{
		s=new char;
	}

	~Ptr()
	{
		delete s;
	}

	Ptr(char *p)
	{
		//s=new char(p); //Do not use it,Error
		s=new char();
		*s = *p; //Mandatory, Use *p to avoid error
	}

	Ptr(const Ptr &obj)
	{
		//s=new char(obj.s); //Do not use it,Error
		s=new char();
		*s=*obj.s; //Mandatory,Use *obj.s to avoid Error
	}

	Ptr& operator=(const Ptr &obj)
	{
		if(this != &obj)
		{
#if 0 //This will modify the destination object
			this->s = new char();
			this->s = obj.s; //Should not use *,V.Imp
#endif
			Ptr *temp;
			temp->s = new char();
			temp->s = obj.s;
			return *temp;
		}
#if 0
		return *this;
#endif
	}

	void display()
	{
		cout<<s<<endl;
	}
};

int main()
{
	char x = 'A';
	char *pt= &x;
	Ptr p1(pt),p2=p1,p3;
	p3=p1;
	p1.display();
	p2.display();
	p3.display();
}
#endif

