#include<iostream>
using namespace std;

#include<stdlib.h>
#include<string.h>

void swap(char *x,char*y)
{
        char *temp = (char*)malloc( sizeof(char)*(strlen(x)+1) ); //V.V.Imp step
        strcpy(temp,x); //Instead of = ,use strcpy
        strcpy(x,y);
        strcpy(y,temp);

        free(temp); //V.Imp
}

int main()
{
        char x[]="Global";
        char y[]="Edge";
        swap(x,y);
        cout<<"Strings After Swapping are:"<<x<<" "<<y<<endl;
}
