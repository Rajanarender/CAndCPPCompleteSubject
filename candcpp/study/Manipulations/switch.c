#include<stdio.h>

int main()
{

	for(int i=0;i<4;i++)
	{
		switch(i)
		{
			case 2:
				printf("%d\n",i);
			case 0:
				printf("%d\n",i);
			default:
                                printf("default\n");
				break;
			case 3: //When controls come here, it automatically gets break out of switch
				printf("%d\n",i);
		}
           printf("Im here\n");
	}
}
