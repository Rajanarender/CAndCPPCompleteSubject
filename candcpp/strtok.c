#include <stdio.h>
#include <stdlib.h>

char *strtok(char *,char *);

int main()
{

    //declaration of variables

    char *string = NULL;
    char *delim = NULL;
    char *res = NULL;

    //memory allocation

    string = malloc (50 * sizeof(int));                                            
    delim = malloc (9 * sizeof(int));                                            
    //reading the strings                                                       

    printf("enter the first string\n");                                           
    fgets(string,200,stdin);                                                       

    printf("\n enter the delimeter string\n");                                        
    fgets(delim,44,stdin); 

    res = strtok(string,delim);
    
    while(res) {
    
        printf("%s\n",res);
        res = strtok(NULL,delim);

    }

    free(string);
    free(delim);
    free(res);
    return 0;
}

char *strtok(char *str, char *del) {

    //declaration section
    
    static char *temp = NULL;
    char *baseadr = del;
    int count = 0;

    if(str == '\0')
        str = temp;
    else
        temp = str;

    if(temp == NULL)
        return NULL;

    while(*str) {
        
        del = baseadr;

        while((*del != '\0') && (*del != *str))
            del++;

        if(*del == *str) {
        
            temp = str + 1;
            *str = '\0';
            return (str - count);
        }

        count++;
        str++;

    }
    
    temp = '\0';
    return (str - count);
}
