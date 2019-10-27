#include<iostream>
using namespace std;
#include<string.h>

/****************************************
strtok(x,"")
=>delimiter should be always double quoted
=>return type of strtok should be *ptr(*token)
=>Only address should be used in while loop , while(ptr/token)
=>Printing the token using address
****************************************/

int main()
{
	char x[]="Global Edge is a MNC\n.It has good amenities\t,With more client locations.";
	char dlmt[]=" \n\t,."; //Delimiter, Write all special letters,etc within double quotes
#if 0
	char dlmt[]=' '; //Error, Delimiter should be within double quotes
#endif
	//char dlmt[]=" "; //Correct,Delimiter

	char *token = strtok(x,dlmt);
	//char *token = strtok(x," \n\t,.");

//Traverse the sentence using Tokenizer(only address)
	//while(*token) //Error 
        while(token) //It should always be address only, V.Imp
	{
		cout<<token<<endl; //Address only Do not derefence it as *token,V.Imp
		token =strtok('\0',dlmt); //Fill tokenizer each time, x is replaced by '\0',V.Imp
		//token=strtok(NULL,dlmt); //this makes strtok to point to next occuring letter/word after delimiter
	}
}
