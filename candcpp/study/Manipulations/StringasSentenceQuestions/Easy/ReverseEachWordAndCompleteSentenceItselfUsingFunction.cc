#include<iostream>
using namespace std;
#include<string.h>

/******************************************************************************
We need 2 local pointers for getting Each word till space and End of sentence
******************************************************************************/

void reverse(char *start,char *end)
{
        while(start < end) //V.V.Imp step
        {
                char tmp = *start;
                *start = *end;
                *end = tmp;
                 start++; //for traversing,Imp step
                 end--; //For traversing.Imp step
        }
}

#if 0 //For reversing each individual word in the sentence
void func(char *x)
{
        char *startaddr=x;
        char *baseaddr=x;
        while(*x)
        {
                if(*x == ' ')
                {
                        reverse(baseaddr,x-1);
                        baseaddr=x+1; //Update the word ptr by changing its address
                }

                x++;
        }
        //if(*baseaddr == '\0') //Condition is not necessary,since *y is NULL obviously after while loop
        //{
                reverse(baseaddr,x-1); //O/p: labolG egdE si a CNM
        //}

}
#endif

#if 1 //For reversing complete sentence
//We need to reverse each individual word and then reverse starting letters with end letters to achieve this
void func(char *x)
{
        char *startaddr=x;
        char *baseaddr=x;
        while(*x)
        {
                if(*x == ' ')
                {
                        reverse(baseaddr,x-1);
                        baseaddr=x+1; //V.V.Imp,Update the word ptr by changing its address
                }

                x++;
        }
        //if(*baseaddr == '\0') //Condition is not necessary,since *y is NULL obviously after while loop
        //{
                reverse(baseaddr,x-1); //O/p: labolG egdE si a CNM
                reverse(startaddr,x-1); //O/p: MNC a is Edge Global
        //}

}

int main()
{
        char x[]="Global Edge is a MNC";
        func(x);
        cout<<x<<endl;
}
#endif


