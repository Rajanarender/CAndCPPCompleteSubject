#include<stdio.h>
#include<string.h>

//Print the substring till space[i.e.,complete word],substring starts with specified character
void func(char *x,int n,char *y)
{
        while(*x)
        {
                if(*x==n) //primary check of character
                {
                        char *temp = x; //Should not affect x, instead store it into a local ptr,V.V.Imp
                        while(*temp != ' ' && *temp != '\0') //V.V.Imp step,NULL for last word in the string
                        {
                                *y++ = *temp++; //copy to destination string
                        }
                        *y = '\0'; //V.V.imp
                        break; //V.V.Imp step, To come out of outer while loop
                }
                x++;
        }
}

//Print the substring till the end of the sentence,substring starts with specified character
char* func1(char *x,int n) //strchr() implementation
{
        while(*x)
        {
                if(*x==n)
                {
                        return x;
                }
                x++;
        }
        return '\0';
}

int main()
{
        char x[]="Global Edge is a CMMI Level3 Company";
        char y[10];
        func(x,'C',y); //O/p: CMMI
        printf("%s\n",y);

        char *ptr = func1(x,'C'); //This is strchr();
        printf("%s\n",ptr); //O/p: CMMI Level3 Company
}
