#include <stdio.h>

// Recursive function to implement atoi() function in C
long atoi(const char *S, int n)
{
	// base case - we have reached end of the string or
	// current character is non-numeric
	if ( n<0 ||(S[n] < '0' || S[n] > '9'))
		return 0;

	// recur for remaining digits and append current digit
	// to result of recusion multiply by 10
	return (10 * atoi(S, n - 1) + (S[n] - '0'));
}

// Implement atoi function in C
int main(void)
{
	char S[] = "123A45";

	printf("%ld", atoi(S, strlen(S) - 1));

	return 0;
}
