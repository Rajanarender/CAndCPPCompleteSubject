#include<stdio.h>
#include<stdlib.h>

int  stringcompare(char *,char *);

int main()
{
	char *str1;
	char *str2;
	int res;
	
	str1=malloc(5 * sizeof(int));
	str2=malloc(5 * sizeof(int));

	printf("enter the first string");
	fgets(str1,15,stdin);

	printf("\n enter the second string ");
	fgets(str2,15,stdin);

	res=stringcompare(str1,str2);
	
	if (res==0)
		printf("\n both the strings are eqaul\n");
	else if (res >0)
		printf("string 1 is greater than string 2\n");
	else
		printf("string 1 is less than string 2\n");
	
	free(str1);
	free(str2);

	return 0;
}

int  stringcompare(char *s,char *t)
{
	int i=0;
	
/*	while((s[i] == t[i]) && (s[i]!='\0') && (t[i]!='\0'))
	{
		i++;
	}
	
	return(s[i] - t[i]);
*/

	if((*s != *t) || (!(*s)) || (!(*t)))
		return (*s - *t);

	return stringcompare(++s,++t);
}
