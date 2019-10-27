#include<iostream>
using namespace std;
//#include<limits.h>
#include<string.h>

#if 1 //Palindrome Check function
bool isPalindrome(char *m,char *n)
{
        char *begin = m;
        char *end = n;
        while(begin <= end) //compare addresses only
        {
                if(*begin != *end)
                {
                        return 0;
                }

                begin++;
                end--;
        }
        return 1;
}
#endif

void func(char *x)
{
        char *start=x;
        char *end =x+1;

#if 0 //We should not use INT_MAX and INT_MIN for Arrays[int,char]
        int maxlen=INT_MAX;
        int minlen=INT_MAX;
#endif
        int maxlen=0; //This can be initialized to any integer like 0,1,3 ,V.V.Imp step
        int minlen=strlen(x); //It is btr to initialize it to strlen(given sentence),V.V.Imp step
        int count=0;

        while(*end)
        {
                if(*end == *start)
                {
                        if(isPalindrome(start,end)) //1st we have to check whether the word is a Palindrome
                        {
                                count++;
                                if(( (end-start) +1 ) > maxlen ) //end-start+1 =lengthofword,start initial value is  0,so add +1,V.V.Imp step
                                {
                                        maxlen = (end-start)+1; //start initial value is  0,so add +1,V.V.Imp step
                                }

                                if(( (end-start) +1 ) <  minlen )
                                {
                                        minlen = (end-start)+1;
                                }

                                //if(*end != '\0') //condition not necessary
                                {
                                        start=end+1; //start has to move to next character
                                        end=end+1; //V.V.Imp step
                                }
                        }
                }

                end++; //End keeps traversing
        }
        cout<<"Palindrome max length: "<<maxlen<<endl;
        cout<<"Palindrome min length: "<<minlen<<endl;
        cout<<"Count of palindromes in the sentence: "<<count<<endl;
}

int main()
{
        char x[]="CIVICRACECARMOMDADROTATORMALAYALAM";
        func(x);
}

