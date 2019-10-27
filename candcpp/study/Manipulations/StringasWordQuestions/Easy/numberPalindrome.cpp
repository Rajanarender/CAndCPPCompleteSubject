#include<iostream>
using namespace std;

int main()
{
        int num = 5225;
        int rev=0;
        int temp = num; //Store number to a local variable
        while(temp!=0)
        {
                rev=rev*10+temp%10;

                temp =temp/10; //Keep traversing by reducing the number
        }
        if(num == rev)
        {
                cout<<"Given Number is a Palindrome"<<endl;
        }
        else
        {
                cout<<"Given Number is NOT a Palindrome"<<endl;
        }
}
