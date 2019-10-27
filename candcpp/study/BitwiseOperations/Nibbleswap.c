#include <stdio.h>

int main() {

        /* byte swapping */
        int a=0x12345678;
        printf("%08x\n",a);

        a = ((a & 0x0ffffff0) | ((a << 28) | a >> 28));
        printf("%08x\n",a);

        return 0;
}
