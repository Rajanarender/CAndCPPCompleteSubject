#include<stdio.h>

/***************************************************
Preprocessor constants:
__FILE__
__FUNCTION__ //__func__ --function macro is so long so typedefed to func
__LINE__
__DATE__
__TIME__

***************************************************/

int main()
{
        printf("%s\n",__FILE__); //prints the file name
        //printf(__FILE__); //prints the file name

        printf(__FUNCTION__); //prints the file name
        printf(__func__); //V.V.Imp prints the file name,this is widely used

        printf("%d\n",__LINE__); //prints the current line number
        //printf(__LINE__); //prints the current line number,Warning Typecasting

        printf("%s\n",__DATE__); //prints current date in MON DD YYYY
        //printf(__DATE__); //prints current date in MON DD YYYY

        printf("%s\n",__TIME__); //prints current time in hh:mm:ss
        //printf(__TIME__); //prints current time in hh:mm:ss
}


