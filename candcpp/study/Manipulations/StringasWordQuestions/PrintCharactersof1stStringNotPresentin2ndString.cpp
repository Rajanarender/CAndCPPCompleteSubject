#include<iostream>
using namespace std;

//We can do this using flags

int main()
{
#if 0 //Array Implemenation
        char x[]="Pranay";
        char y[]="Vinay";
        //bool flag =false; //if k=1 => flag=true, if k=0 => flag=false
        int flag =false;
        for(int i=0;x[i] !='\0';i++)
        {
                for(int j=0;y[j] !='\0';j++)
                {
                        if(x[i] != y[j])
                        {
                                flag=true;
                        }
                        else //V.V.Imp,flag has to be reset when characters are same
                        {
                                flag=false;
                                break;//V.V.Imp step
                        }
                }
                if(flag == true) //For unique[not same] characters
                {
                        cout<<x[i]<<endl;
                }
#if 0
                if(flag == false) //For same characters
                {
                        cout<<x[i]<<endl;
                }
#endif
        }
#endif

#if 1
        const char*x="PranDay";
        const char*y="Vinay";
        const char*baseaddr=y; //Preserve base address into other ptr
        int flag= false;

        while(*x)
        {
                while(*y)
                {
                        if(*x != *y)
                        {
                                flag= true;
                        }
                        else //V.V.Imp,flag has to be reset when characters are same
                        {
                                flag= false;
                                break; //V.V.Imp,atleast one set of characters are equal is enough,so break
                                       //break will stop overwriting the flag to true
                        }

                        y++;
                }
                y=baseaddr; //V.V.Imp step,Redirect ptr to base address

                if(flag == true) //For unique[not same] characters
                {
                        cout<<*x<<endl;
                }
                else //For same characters
                {
                        cout<<*x<<endl;
                }

                x++;
        }
#endif
}

