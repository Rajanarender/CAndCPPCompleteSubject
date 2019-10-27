#include<stdio.h>
#include<stdlib.h>

//function declaration

char * substring(char *,char *);

int main()
{
    //defining variables

	char *str1;
	char *str2;
	char * res;
	
    //allocating memory

	str1 = malloc (6 * sizeof(int));
	str2 = malloc (6 * sizeof(int));

    //reading the strings

	printf("enter the first string");
	fgets(str1,24,stdin);

	printf("\n enter the sub  string ");
	fgets(str2,24,stdin);

    //function call

	res=substring(str1,str2);
	
	if (res != 0)
		printf("\n The sub string is %s\n",res);
	
    else
		printf("\n the substring is not found\n");

	//memory free

    free(str1);
	free(str2);
    
    str1=NULL;
    str2=NULL;

	return 0;
}

//function definition

char * substring(char *s,char *ss)
{
	//defining variables

	int flag = 0;
	char *temp = ss;

	//traversing upto the end of string

	while(*s != '\n')
	{

		//assigning the starting address to substring
		ss=temp;

		//traversing upto the end of the substring and comparing the substring
		//with the string

		while ((*ss != '\n') && (*ss == *s)) {

			//checking whether the next character of the substring is '\n' and
			//also the next character of two strings

			if(*(ss+1)!='\n' && (*(ss+1) != *(s+1)))
				break;

			flag++;
			s++;
			ss++;
		}

		if (*ss != '\n') {

			flag=0;

		}

		else {
			return  (s - flag);
		}
		s++;

	}
	return 0;
}
