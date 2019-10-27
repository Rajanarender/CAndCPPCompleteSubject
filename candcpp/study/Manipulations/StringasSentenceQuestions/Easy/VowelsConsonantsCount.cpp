#include<iostream>
using namespace std;


int main()
{
        const char*x ="Gobal Edge is a view MNC";
        int vowelscount=0;
        int consonantscount=0;
        while(*x)
        {
                if(*x != ' ') //V.V.Imp,Eliminating spaces
                {
                        if(*x=='A'|| *x=='E'||*x=='I'||*x=='O'||*x=='U'||*x=='a'|| *x=='e'||*x=='i'||*x=='o'||*x=='u')
                        {
                                vowelscount++;
                        }
                        else
                        {
                                consonantscount++;
                        }
                }

                x++;
        }
        cout<<"vowels count is: "<<vowelscount<<endl;
        cout<<"consonants count is: "<<consonantscount<<endl;
}
