#include<iostream>
using namespace std;
#include<string.h>

/***************************************************************
Palindrome:
definition:
If the string is same, even after we reverse
If the string first and last characters remains same while traversing parallely

condition for Palindrome:
        while(start < end) //Address check, start should always be lesser than end(Never keep equal to), V.V.Imp
        {
                if(*start != *end) //Value check
                {
                        cout<<"Given string is not a Palindrome"<<endl;
                        return; //V.V.Imp step
                }

                start++;
                end--;
        }
        cout<<"Given string is a Palindrome"<<endl;
-------------------------------------------------------------------------

condition for strrev():
        while(start < end)
        {
                //swap(start,end);
                   //(or)
                char temp = *start;
               *start =*end;
                *end = temp;

                start++;
                end--;
        }
***************************************************************/

Pointer Implementation:
=========================
void func(char *x)
{
        char *start=x;
        char *end= x+strlen(x)-1; //strlen(x)-1,since index starts from 0
        while(start < end) //V.V.Imp,Address check
        {
                if(*start != *end) //Value check
                {
                        cout<<"Given string is not a Palindrome"<<endl;
                        return; //V.V.Imp step
                }
                start++;
                end--;
        }
        cout<<"Given string is a Palindrome"<<endl; //V.V.Imp step,Should be outside the loop
}

Array Implementation:
=======================
void func1(char x[])
{
        for(int i=0;i<strlen(x)/2;i++) //strlen()/2, V.V.Imp step
        {
                if( x[i] != x[strlen(x)-1-i] )
                {
                        cout<<"Given string is not a Palindrome"<<endl;
                        return; //V.V.Imp step
                }
        }
        cout<<"Given string is a Palindrome"<<endl; //V.V.Imp step,Should be outside the loop
}

int main()
{
        char x[] ="MALAYALAM"; //Do not do strrev() for this source string
        func(x);

#if 1 //Normal Implementation
        char temp[strlen(x)+1];
        strcpy(temp,x); //store source string into a local variable

        strrev(temp);
        if(strcmp(x,temp)==0)
        {
                cout<<"Given string is a Palindrome"<<endl;
        }
        else
        {
                cout<<"Given string is not a Palindrome"<<endl;
        }
#endif
}
