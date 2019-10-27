#include<stdio.h>
#include<stdlib.h>

int main()
{
	int mat[2][2][2]={{1,2,3},{4,5,6}};//3D 
	int height=2,rows=2,columns=2; //We can use macros instead

#if 1 //Allocate memory
	int ***x=(int***)malloc(sizeof(int**)*height);
	//x[i][j]=(int*)calloc(columns,sizeof(int));
        //char ***x = new int **[height];
 
	for(int i=0;i<height;i++)
	{
		x[i] = (int**)malloc(sizeof(int*)*rows);
		//x[i] = (int**)calloc(rows,sizeof(int*));
                //x[i] = new int*[rows];

		for(int j=0;j<rows;j++)
		{
			x[i][j]=(int*)malloc(sizeof(int)*columns);
			//x[i][j]=(int*)calloc(columns,sizeof(int));
                        //x[i][j] =new int[columns];
		}
	}
#endif

#if 1 //Deallocate memory
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<rows;j++)
		{
			free(x[i][j]);
                        //delete []x[i][j];
		}

		free(x[i]);
                //delete []x[i];
	}
	free(x);
        //delete []x;
#endif
}

