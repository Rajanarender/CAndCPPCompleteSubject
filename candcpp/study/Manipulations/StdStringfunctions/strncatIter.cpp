#include<iostream>
using namespace std;

/****************************************
strncat()
-----------

Pointer Implementation:
=========================
****************************************/

char* func(char *d, const char *s,size_t sz) //source string src should be made constant so that its value cannot  be modified while copying
{
	char *temp = d;
	if(sz) //V.V.Imp step
	{
		while(*d)
		{
			d++;
		}

		int k =0;
		while(sz)
		{
			*d++ = *s++;// Optimized code
			//*d =*s;
			//s++;
			//d++;
			sz--;
		}
	}
        return temp;
}

#if 0
Array Implementation:
========================

void func(char d[], char s[],int bytes)
{
    int i =0,j=0;

    while(d[i])
    {
        i++;
    }

    int k =0;
    while(s[j] && k<bytes)
    {
        d[i] = s[j];
        i++;
        j++;
        k++;
    }
    d[i] ='\0';
}
#endif

int main()
{
    char src[]="Edge";
    char des[11] ="Global";//Should we specify the destination size b4 concating the source
    cout<<func(des,src,2)<<endl;//Pass by Reference,So no need to have Return type
    cout<<des<<endl;
}
