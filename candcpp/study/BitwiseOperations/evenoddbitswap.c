#include <stdio.h>

int main() {
	int n =8;
	int i;
	for (i=0;i<8;i=i+2) {
		printf("%d  ", n&(1<<i));
		printf("%d\n", n&(1<<(i+1)));
		if((!!(n&(1<<i))) != (!!(n&(1<<(i+1))))) {
			n = n^(1<<i);
			n = n^(1<<(i+1));
		}
	}
	printf("res = %d\n",n);
}

