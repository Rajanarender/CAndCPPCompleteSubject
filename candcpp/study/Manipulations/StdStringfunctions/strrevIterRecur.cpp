strrev()
----------

Pointer Implementation:
=========================
void swap(char*x, char*y)
{
    char temp =*x;
    *x = *y;
    *y =temp;
}

#if 0 //2ptrs *start,*end
void func(char *str)
{
    char *start = str;
    char *end = str+strlen(str)-1; //strlen() is must, so that end ptr can point to the last index

    while(start<end) //compare start and end address
    {
        //swap(start,end); //We can use swap function (or) the below code
        char temp = *start;
        *start =*end;
        *end = temp;
        start++;
        end--;
    }
}
#endif

#if 1 //Instead of 2ptrs, we can use only one ptr *end
void func(char *str)
{
    char *end = str+strlen(str)-1; //strlen() is must, so that end ptr can point to the last index

    while(str<end) //compare start and end address
    {
        //swap(str,end); //We can use swap function (or) the below code
        char temp = *str;
        *str =*end;
        *end = temp;
        str++;
        end--;
    }
}
#endif


Array Implementation:
=======================
void func(char str[])
{
    int len = strlen(str);
    int i;
    for(i = 0; i < len/2 ; i++)
    {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

**********************************
Recursive Method:
**********************************

Pointer Implementation:
=========================

#if 1 //Prints one by one character in reverse
//This function doesnot actually reverse the string
void func(char *s)
{
        if(*s == '\0')
                return;

        func(s+1);
        cout<<*s; //Due to stack frames,printing characters from end
}
#endif

void swap(char *x, char *y)
{
        char temp = *x;
        *x = *y;
        *y = temp;
}

// recursive string reverse takes 2 ptrs as arguments 
void recurfunc(char *s, char *end)
{
        if(s<end)
        {
                swap(s,end);
                recurfunc(s+1,end-1);
        }
        //return; //Not mandatory
}


int main()
{
    char str[]="Global";
    func(str); //This is Pass By reference, So no Need of return type
    printf("%s\n",str);

#if 0 // We can write like this also
    char *end = str+strlen(str) -1;
    recurfunc(str,end); 
#endif
    recurfunc(str, str+strlen(str)-1); //2 parameters for recursive reverse of string 
}





