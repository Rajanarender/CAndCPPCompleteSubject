#include<stdio.h>
#include<string.h>

/****************************************************************************
memcpy:
overlaps happens when you copy complete string to substring of the same string
Due to overlapping of memory in the resultant string, the expected result will not come
NOTE: overlap happens mostly when src,dest are of same string parts

memmove:
Here memory overlap will not happen when copying src to dest.
Expected result come here
****************************************************************************/

int main()
{
  char x[] = "Global Edge";
  memcpy(x+7,x,strlen(x)+1); //strlen(x)+1, Include '\0' character also
  printf("%s\n",x); //o/p: Global Global Globa

  char y[] = "Global Edge";
  memmove(y+7,y,strlen(y)+1);
  printf("%s\n",y); //o/p: Global Global Edge
}
      
