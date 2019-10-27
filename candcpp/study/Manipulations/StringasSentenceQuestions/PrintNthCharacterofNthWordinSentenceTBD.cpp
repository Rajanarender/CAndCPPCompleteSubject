#include<stdio.h>
#include<string.h>

int main()
{
        const char s[100]="Global Edge bad is a MNC Global Edge is locatediin in Tech Park Tech Park is Good";
        int wlen=0,wc=0;

        for(int i=0;s[i] != '\0';i++)
        {
                if(s[i] != ' ')
                {
                        wlen++;
                }
                else
                {
                        if(wc < wlen)
                        {
                                printf("%c\t",s[i+wc-wlen]);
                        }
                        else if(wlen > wc)
                        {
                                printf("*\t");
                        }
                        else
                        {
                                printf("*\t");
                        }
                        wlen=0;
                        wc++;
                }
        }
}
