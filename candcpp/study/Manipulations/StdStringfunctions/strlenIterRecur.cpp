strlen()
----------

Alternate way for Pointer Implementation:
=========================================
//1st Method:
size_t func(const char *y)
{
    int count = 0;
    while(*y)
    {
        count++;
        y++;
    }
    return count;
}


Pointer Implementation: //Without using count variable
========================
size_t func(const char *y)
{
    char *start =y; //store the base address
    while (*y)
    {
        y++;
    }
    return (y-start); //Just subtract the addresses of 1st and last ptrs
}

Array Implementation:
=======================
int func(char y[])
{
#if 0
    int i =0;
    while(y[i]) // (or) while (y[i] != '\0')
    {
        i++;
    }
#endif

    for(int i =0; y[i] != '\0';i++)
    {
    }
    return i;
}

int main()
{
    char x[] ="Global Edge";
    cout<<func(x)<<endl;
}

**********************************
Recursive Method:
**********************************

Pointer Implementation:
=========================
int recurfunc(char *s)
{
       if(*s == '\0')
         return 0;

      return 1+recurfunc(s+1); //Should not use s++,it leads to segmentation fault ,V.V.Imp step
}

int main()
{
     //   char src[] ="GlobalEdge";
	char *src= NULL;
        cout<<recurfunc(src)<<endl;
}




