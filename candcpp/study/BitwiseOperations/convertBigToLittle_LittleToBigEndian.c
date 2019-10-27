
#include <stdio.h>

int main() {

        /* byte swapping */
        int a=0x12345678;
        printf("%08x\n",a);

        a = ((a & 0x00ffff00) | ((a << 24) | a >> 24));
        a = ((a & 0xff0000ff) | (((a & 0x0000ff00) << 8) | ((a & 0x00ff0000) >> 8)));
        printf("%08x\n",a);

        return 0;
}
