#include<iostream>
using namespace std;

void wordfunc(char *begin,char *end,char *buf)
{
        while(begin<=end) //<= is Imp ,since we need to copy all alphabets to w
        {
                *buf++ = *begin++;
        }
        *buf='\0'; //V.V.Imp
}

void func(char *x)
{
        char ch;
        cout<<"Enter Ending character of a Word from the sentence\n";
        cin>>ch;

        char *baseaddr=x;
        char buf[11]; //Buffer to hold the Word[Word ending with specified character]
        while(*x)
        {
                if(*x == ' ') //Space character
                {
                        if( *(x-1) == ch ) //Ending character check
                        {
                                wordfunc(baseaddr ,x-1,buf);//V.V.Imp
                                cout<<buf<<endl; //Print buf
                        }
                        baseaddr=x+1; //V.Imp step, It should be here only
                }

                x++;
        }
        //if(*x=='\0' && *(x-1) == ch) //NULL character and Ending character check,No need of this condition
        if(*(x-1) == ch) //Ending character check is enough,since x is NULL here
        {
                wordfunc(baseaddr,x-1,buf);
                cout<<buf<<endl; //Print buf
        }
}

int main()
{
        char x[] ="All Globalites Indians are Experts";
        func(x);
}

