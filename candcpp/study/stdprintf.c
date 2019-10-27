#include<stdio.h>

/************************************************************
printf() returns the number of characters of the word passed
*************************************************************/

int main()
{
  int x = printf("Gesl"); //Gesl
  printf("\n");
  printf("%d\n",x); //4
  printf("%d\n",printf("Gesl")); //Gesl4 
  printf(3+"Gesl Edge"); //l Edge
  printf("\n");
  printf("Gesl Edge"+6); //dge
}
 
