
void stringreverse(char *word)
{
	char *start = word;
	char *end = start+strlen(word)-1;
	while(start < end) 
	{
		swap(start,end);

		start++;
		end++;
	}
}

Bool IsPalindrome(char *word)
{
        char *start = word;
        char *end = start+strlen(word)-1;
	while(start < end) //Compare only addresses
	{
		if(*start != *end) //V.Imp condition
		{
			cout<<"Not a Palidrome\n";
			return 0;
		}
		start++;
		end++;
	}
	cout<<"Is a Palidrome\n";
        return 1;
}

int stringcompare(char *m, char *n)
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


