
/*************************************
strncpy(des,src,srcbytes)
Instead of copying the complete data of src to des,
We can copy on part of source to destination by specifying the bytes/character count
NOTE: Do not make the destination to NULL(*d ='\0')
since we need destination data to be existing apart from copied source data
**************************************/

**********************************
Iterative Method:
**********************************

Pointer Implementation:
=========================
void func(char *d, const char *s,int bytes) //source string src should be made constant so that its value cannot be modified while copying
{
    int i = 0;
    while(*s && i<bytes)
    {
        *d++ = *s++;// Optimized code
        //*d =*s;
        //s++;
        //d++;
        i++;
    }
    *d= '\0'; //V.V.Important step
}

Array Implementation:
=========================
void func(char d[], char s[],int bytes)
{
    int i = 0;
    while(s[i] && i<bytes)
    {
        d[i] = s[i];
        i++;
    }
    d[i]='\0';
}

int main()
{
    //const char *src ="GlobalEdge"; we cannot modify const
    char src[] ="GlobalEdge";
    char des[11]; //Should we specify the destination size b4 copying from source
    func(des,src,4);//Pass by Reference,So no need to have Return type
    cout<<des<<endl;
}


