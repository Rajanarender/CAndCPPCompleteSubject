/*******************
strcat()
*******************/

Pointer Implementation:
=========================
char* func(char *d, const char *s) //source string src should be made constant so that its value cannot  be modified while copying
{
	char* temp =d;
	while(*d)
	{
		d++;
	}
	while(*s)
	{
		*d++ = *s++;// Optimized code
		//*d =*s;
		//s++;
		//d++;
	}
	*d ='\0'; //V.V.Important step
	return temp;
}

Array Implementation:
========================
char* func(char d[], char s[])
{
    int i =0,j=0;

    while(d[i])
    {
        i++;
    }
    while(s[j])
    {
        d[i] = s[j];
        i++;
        j++;
    }
    d[i] ='\0';
}

**********************************
Recursive Method:
**********************************

Pointer Implementation:
=========================

//Here if and else conditions are mandatory,program does not wrk if we dont use them
void func(char *d, char *s)
{
        if(*d != '\0')
        {
                func(d+1,s);
        }
	else //V.Imp,this else part implementation is same as recursive strcpy()
        {
                if(*s == '\0') //V.V.Imp
                {
                        *d = '\0';
                        return; //V.V.Imp
                }
                *d=*s;
		func(d+1,s+1); //After copying s to d, d moves to  next position('\0' position), so code always enters into else condition 
        }
}

int main()
{
    char src[]="Edge";
    char des[11] ="Global";//Should we specify the destination size b4 concatinating the source
    cout<<func(des,src);//Pass by Reference,need to have Return type
    cout<<des<<endl;
}

