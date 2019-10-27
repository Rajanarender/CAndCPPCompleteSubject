#include<stdio.h>

/************************************************************************
rewind(fp) -Used to change the fptr position to the beginning of file
feof(fp) -END OF FILE

No separator header needed for C files,since they are included in stdio.h itself

API's in file
fopen()
fclose()
fprint() -Writes the data to file by passing format specifiers
fscanf() -Reads the data from file by passing format specifiers
getc() -reads single character at a time from file
putc() -writes single character at a time from file

fseek(fp,,) -sets the fp position to desired location 
ftell(fp) - returns the fp position in integer format
rewind(fp) -sets the fp position to the starting of file
*************************************************************************/

int main()
{
	FILE *fp;
	fp = fopen("filesizec.txt","w");
	if(!fp) //if(fp==NULL)
	{
		printf("File doesnot Exist,Please create it\n");
	}
	fprintf(fp,"Global Edge224"); //Writting into the file

	//while(!feof(fp))
	//{
	//}

	fclose(fp);

	fp = fopen("filesizec.txt","rb"); //read,binary mode,V.V.Imp step
	int start = ftell(fp);

#if 0
	//SEEK_SET for beginning,SEEK_CUR for current,SEEK_END for end
	//When we use SEEK_SET, fp traverse forward(+) direction
	fseek(fp,0,SEEK_SET); //fp points to 0th position(start of line) 
	fseek(fp,1,SEEK_SET); //fp points to 1st position 
	fseek(fp,2,SEEK_SET); //fp points to 2nd position 
	fseek(fp,-1,SEEK_SET); //ERROR,Does not work

	//When we use SEEK_END, fp traverse backward(-) direction
	fseek(fp,0,SEEK_END); //fp points to last position(end of line) 
	fseek(fp,-1,SEEK_END); //fp points to last-1 position(end of line) 
	fseek(fp,-2,SEEK_END); //fp points to last-2 position(end of line) 
	fseek(fp,1,SEEK_END); //ERROR,Does not work

	//When we use SEEK_CUR, fp traverse in both forward(+) and backward(-) directions
	fseek(fp,0,SEEK_CUR); //fp points to current position
	fseek(fp,-1,SEEK_CUR); //fp points to current position-1
	fseek(fp,2,SEEK_CUR); //fp points to current position+2
#endif

#if 1 //If we want to see the content of the file
	fseek(fp,-2,SEEK_END);
	while(!feof(fp))
	{
		printf("\n%c\n",getc(fp));
	}
#endif

	fseek(fp,0,SEEK_END);
	int end = ftell(fp);
	fclose(fp);
	printf("size of filesizec.txt is %d Bytes\n",(end-start));
}
