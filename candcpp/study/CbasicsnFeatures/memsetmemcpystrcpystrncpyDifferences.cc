#include <string.h>

void *memset(void *dest, int k, size_t n);
memset fills/replaces n bytes of dest memory area with constant data k

return:
memset returns pointer to dest 
**************************************************************************************************************
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n);

memcpy copies n bytes of memory area from src to dest directly

Description:
memcpy() directly copies n bytes of src memory area to destination memory area, since this may lead to overlap of memory areas sometimes
Use memmove() to avoid this overlap
**************************************************************************************************************

#include <string.h>
void *memmove(void *dest, const void *src, size_t n);

memmove copies n bytes of memory area from src to dest via temporay array

Description:
memmove() does not directly copy n bytes of src memory area to destination memory area, since this leads to overlap of memory areas.
To avoid this overlap,memmove uses temporary array.
1st n bytes of src memory area is copied to temporary array
Now this temporary array is copied to dest memory area

return:
memmove returns a ptr to dest
**************************************************************************************************************

#include <string.h>
void *strcpy(void *dest, const void *src);
void *strncpy(void *dest, const void *src,size_t n);

strcpy copies complete string data(including '\0' character) of src to dest (No restrition on data coping)
strncpy copies only specific n string data from src to dest 
 
return:
Both strcpy and strncpy returns a ptr to dest
**************************************************************************************************************


#include<iostream>
using namespace std;
#include<string.h>

int main()
{
	char x[] ="Global Edge";
	memset(x,'A',6); 
	cout<<x<<endl; //AAAAAA Edge
	memset(x,100,6); //100 is ASCII value of 'd'
	cout<<x<<endl; //dddddd Edge
	memset(x,0,6); 
	cout<<x<<endl; //Empty spaces
	memset(x,'\0',6); //if you pass NULL, leads to Warning,so use '\0' only
	cout<<x<<endl; //Empty spaces 

	char y[] = "Altran";
	memcpy(x,y,6);
	cout<<x<<endl; //Altran Edge

	strncpy(x,y,6);
	cout<<x<<endl; //Altran Edge

	strcpy(x,y);
	cout<<x<<endl; //Altran
}
