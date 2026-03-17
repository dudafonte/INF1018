#include <stdio.h>
#include <stdlib.h>

unsigned char switch_byte(unsigned char x)
{   
    x = (x >> 4) | (x << 4);
    return x;
}

int main(void)
{
    unsigned char x = 0xAB;
    unsigned char resp = switch_byte(x);
    printf("antes: 0x%X\ndepois: 0x%X\n", x, resp);

    return 0;
}