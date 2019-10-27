#include<iostream>
using namespace std;


//For positions questions,Use array implementation only, not pointers
int main()
{
#if 1
	const char *x = "Global Edge is a MNC";
	const char *baseaddr = x;

	while(*x)
	{
		if( (x-baseaddr)%2 == 0) //Address only,V.Imp
		{
			cout<<"Even Position alphabets are : "<<*x <<endl;
		}
		else if( (x-baseaddr)%2 == 1)
		{
			cout<<"Odd Position alphabets are :"<<*x <<endl;
		}
		x++;
	}
#endif

#if 0 //Array Implementation, Not needed
        char x[]="Global Edge is a MNC";
        for(int num =2;x[num];num++) //Here num is index of the array, that starts from 0
        {

#if 0 //Enable this, if you want to avoid/skip spaces
                if(x[num] == ' ')
                        continue;
#endif

#if 1 //Prime Number Implementation, No need of this
                int count=0;
                for(int i=1;i<=num;i++)
                {
                        if(num%i==0)
                        {
                                count++;
                        }
                }
                if(count == 2) //number devided by 1 and itself is Prime Number
                {
                        cout<<x[num-1]<<endl; //x[num-1],since the alphabets are starting from 1 but index(num) starts from 0
                }
#endif

#if 0
                if(num%2 ==0 )
                        cout<<x[num]<<endl;;
                else if(num%2 ==1)
                        cout<<x[num]<<endl;
#endif
        }
#endif

}
