#include<iostream>
using namespace std;


int func(char *s)
{
    if(s == NULL) //Corner Case ,To Avoid Segmentation fault
     return 0;

    return *s ? func(s+1)+1:0; //Single line Optimized code having Base condition *s=='\0'
}

int main()
{
#if 0
	cout<<func(NULL); //Corner case
 
        cout<<func("Gesl");//Warning ,Runs fine
#endif
        char x[]="Gesl";
        cout<<func(x)<<endl;
}
