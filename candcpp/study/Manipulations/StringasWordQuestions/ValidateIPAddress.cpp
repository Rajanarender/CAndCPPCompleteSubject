#include<iostream>
using namespace std;
#include<stdlib.h>

/*******************************************
  Check Each character is within '0' to '9'
  Check total digit before dot is within 0 to 255
  Check the Number of dots is equal to 3
  Check the Number of digits count is b/w 1 to 3
 *******************************************/

//For each octet
void word(char *m , char *n)
{
	char *baseadr = m;
	int digitcount=0;
	while(m <= n) // Traversing through each single digit
	{
		digitcount++;
		if(!(digitcount >= 1 && digitcount <= 3))
		{
			cout<<"Given IPaddress is invalid: "<<__LINE__;
			exit(0);
		} 

		if(!(*m >= '0' && *m <= '9')) //0 and 9 are of character type,so use single quotes,V.V.Imp
		{
			cout<<"Given IPaddress is invalid: "<<__LINE__;
			exit(0);
		}

		if(m == n) //End of octet
		{
			int num = atoi(baseadr); //V.V.Imp
			cout<<"The digit is: "<<num<<endl;
			if(!(num >=0 && num <=255)) //Each complete octet should be with 0 to 255
			{
				cout<<"Given IPaddress is invalid: "<<__LINE__;
				exit(0);
			}
		}
		m++; //V.V.Imp step
	}

#if 0 //This is wrong,Do not use this code
	if(*m == '\0') //*m cannot be NULL here
	{
		int num = atoi(baseadr);
		cout<<num<<endl;
		if(!(num >=0 && num <=255))
		{
			cout<<"Given IPaddress is invalid: "<<__LINE__;
			exit(0);
		}

	}
#endif
}

int main()
{
	//i/p: 12a.0.255.12 //Each character 0-9 check
	//i/p: 126.258.1.5 //Every digit 0-255
	//i/p: 121.5.6.7.128 //Total No. of dots should be 3 only

	char x[]="2554.30.50.0.60";  // we can also use string tokenizer char *k=strtok(x,'.') to separate the digits
	char *temp =x; //ptr to array
	char *y=x;
	int dotcount=0;
	while(*temp)
	{
		if(*temp == '.')
		{
			dotcount++;
			word(y,temp-1); //Each octet as a time
			y=temp+1;
		}
		temp++;
	}
	word(y,temp-1); //V.V.Imp

	if(dotcount!=3)
	{
		cout<<"Given IPaddress is invalid: "<<__LINE__;
		exit(0);
	}
	cout<<"Given IPaddress is a valid IP\n";
}
