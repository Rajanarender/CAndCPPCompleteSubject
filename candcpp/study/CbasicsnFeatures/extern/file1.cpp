#include<iostream>
using namespace std;

/*******************************************************
extern:Extending the scope of local variable to global and accessing within multiple files
default value: 0
scope: Global scope within multiple files,Alive till the completion of the program
storage:globally unitialized segment,BSS in DATA segment
syntax:
extern int x =0;//WARNING
extern int x;//Only Declaration is allowed

NOTE: if int x is not defined in any other file,Linking error occurs 
********************************************************/
extern int var; //It Keeps searching for definition,If definition is not found,throws Linking ERROR 
extern int var=10; //WARNING,it takes 10 
//void func();
int main()
{
	//func();
	cout<<"File1:var is: "<<var<<endl;
	extern int x;
	cout<<"File1:x is: "<<x<<endl;
}

int x =100;
