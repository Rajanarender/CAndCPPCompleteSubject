#include <stdio.h>

int main() {
	unsigned int num=39;
	int p1=3,p2=6;

	num = (((1<<(p2-1)) - 1) & (num >> (p1-1)));
	printf("res = %d\n",num);
	return 0;
}
