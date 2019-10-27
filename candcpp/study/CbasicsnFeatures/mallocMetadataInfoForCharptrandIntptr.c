#include <stdio.h>
#include <stdlib.h>

int main() {

	//char *ptr = (char *)malloc(10);
	int *ptr = (int *)malloc(10);


	if (ptr == NULL) {
		printf("fail\n");
		return 0;
	}

	printf("%x\n", *(ptr-1));
	printf("%x\n", *(ptr-2)); //int ptr will traverse by 4 bytes,since address(int) is 8 bytes, ptr-2
#if 0
	printf("%x\n", *(ptr-3));
	printf("%x\n", *(ptr-4));
	printf("%x\n", *(ptr-5));
	printf("%x\n", *(ptr-6));
	printf("%x\n", *(ptr-7));
	printf("%x\n", *(ptr-8)); //character ptr will traverse by 1 byte,since address(int) is 8 bytes, ptr-8
#endif
	free(ptr);

	return 0;
}
