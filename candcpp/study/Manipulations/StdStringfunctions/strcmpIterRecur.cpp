strcmp()
----------

Pointer Implementation:
=========================
Bool IsPalindrome(char *m,char *n)
{
	while(*m && *n) //Checking character by character till NULL character
	{
		if(*m != *n) //V.Imp condition
		{
			cout<<"Not a Palidrome\n";
			return 0;
		}
		m++;
		n++;
	}
	cout<<"Is a Palidrome\n";
        return 1;
}

int func(char *m, char *n)
{
	while(*m && *n) //Checking character by character till NULL character
	{
		if(*m != *n) //V.Imp condition
		{
			break; //Mandatory
		}
		m++;
		n++;
	} //This code comes out of loop when *m or *n or both become NULL
	return(*m-*n);//ASCII value difference
}

Array Implementation:
=========================
int func(char m[], char n[])
{
	int i = 0;
	while(m[i] && n[i])
	{
		if(m[i] != n[i])
		{
			break;
		}
		i++;
	}
	return (m[i] - n[i]);

}

**********************************
Recursive Method:
**********************************

Pointer Implementation:
=========================
int func(char *m,char *n)
{
	if(*m != *n) //V.V.Imp 
	{
		return(*m-*n);//ASCII value difference
	}
	else if(*m == '\0' && *n == '\0') //Imp step, NULL check for both strings
	{
		return 0;
	}

	func(m+1,n+1);
}

int main()
{
    char x[] = "RAjZ";//ASCII value for [a to z]= 97 to 122
    char y[] = "RajA";//ASCII value for [A to Z]= 65 to 90
    cout<<func(x,y)<<endl;
       /*
        if x == y, func(x,y) returns 0
        if x > y, func(x,y) returns Positive number(ASCII value)
        if x < y, func(x,y) returns Negative number(ASCII value)
        Here func(x,y) is strcmp(x,y)
       */
}

