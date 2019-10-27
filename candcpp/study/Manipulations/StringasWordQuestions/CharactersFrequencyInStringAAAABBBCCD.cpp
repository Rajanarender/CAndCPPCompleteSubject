#include<iostream>
using namespace std;
#include<string.h>

int main()
{
        const char *x ="AAAABBBCCD";  //Mixed characters[upper,lower case]

#if 0 //Instead of this, use the below code  
        int freq[3] = {0,0,0};
#endif
        int freq[3] = {0}; //Initialize each element of array to ZERO ,V.V.V.Imp step
          
        while(*x)
        {
                //if(*x >= 'A' && *x <='Z') //No need of this condition
                {
                        freq[*x - 65]++; //++ is very Important,V.V.Imp step
                }
                x++;
        }

#if 0 // o/p:A4B3C2D1
        for(int i=0;i<4;i++) //i<4,Since only 4 characters are present in the given array
        {
                //if(freq[i] != 0) //V.V.Imp step, To avoid indexes with value 0
                {
                        cout<<(char)(i+65)<<freq[i]; //Typecasting is must
                }
        }
#endif

#if 0 // o/p:A4B3C2D
for(int i=0;i<4;i++) //i<4,Since only 4 characters are present in the given array
{
        //if(freq[i] != 0) //V.V.Imp step, To avoid indexes with value 0
        {
                cout<<(char)(i+65); //V.V.Imp step
                if(freq[i] > 1)
                {
                        cout<<freq[i];
                }
        }
}
#endif

#if 1 // Maximum and Minimum Frequency characters
        int max=freq[0]; //Should be initialized mandatorily,V.V.Imp
        int maxchar;
        int min=freq[0]; //Should be initialized mandatorily,V.V.Imp
        int minchar;

        for(int i=0;i<4;i++)
        {
                //if(freq[i] != 0) //V.V.Imp step, To avoid indexes with value 0
                {
                        if(freq[i] >= max) //>= is Imp
                          {
                          max=freq[i];
                          maxchar=i; //i is the character,V.V.imp
                          }

                        if(freq[i] <= min)
                          {
                          min=freq[i];
                          minchar=i; //i is the character,V.V.imp
                          }
                }
        }
       cout<<"Maximum frequency Occuring Character is:"<<char(maxchar+65)<<endl; //Typecasting is must
       cout<<"Minimum frequency Occuring Character is:"<<char(minchar+65)<<endl;
#endif

}


