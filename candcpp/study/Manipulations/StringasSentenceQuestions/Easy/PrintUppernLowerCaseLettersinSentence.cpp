#include<iostream>
using namespace std;
#include<ctype.h>

/***********************************************
isalpha() -It accepts only alphabets,eliminates special characters,numbers
***********************************************/

int main()
{
        const char *x="GloBal @^~$#*EdGe2257";
        int uppercount=0;
        int lowercount=0;
        while(*x)
        {
                // if(*x >='A' || *x <= 'Z' || *x >='a' || *x <= 'z')
                if(isalpha(*x)) //It eliminates all special characters and numbers,V.V.Imp
                {
                        if(isupper(*x))
                        {
                                uppercount++;
                                cout<<"Upper Case letters are:"<<*x<<endl;
                        }
                        else if(islower(*x))
                        {
                                lowercount++;
                                cout<<"Lower Case letters are:"<<*x<<endl;
                        }
                }

                if(isdigit(*x)) //It accepts only numbers
                {
                        cout<<"Numbers are:"<<*x<<endl;
                }

                x++;
        }
        cout<<"No.of Upper case letters: "<<uppercount<<endl;
        cout<<"No.of Lower case letters: "<<lowercount<<endl;

}
