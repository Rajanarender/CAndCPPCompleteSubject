#include<stdio.h>
#include<string.h>

char* func(char *x,int n)
{
        x = x+strlen(x)-1; //V.V.Imp step,making the ptr to point at the string end
	while(*x)
	{
               if(*x == n)
                return x;

		x--; //V.V.Imp step
	}
        return '\0';
}


int main()
{
	char x[]="Global Edge is a CMMI Levelp3 Company";
	//char *ptr = strrchr(x,'p');
        char *ptr=func(x,'C'); 
	printf("%s\n",ptr);
       //cout<< ptr; //This is not working, so use printf only
#if 1
	char y[]="Global Edge EdAge";
	char *p = strchr(y,"l"); //Should not use the source string directly
	printf("strchr(): %s\n",p);
        char *p1 = strrchr(y,'E'); //Should not use the source string directly
	printf("strrchr(): %s\n",p1);

	char *p2=strstr(y,"al"); //Should not use the source string directly
	printf("strstr(): %s\n",p2);
#endif
}
