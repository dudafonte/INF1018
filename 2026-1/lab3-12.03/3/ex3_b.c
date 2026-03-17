#include <stdio.h>
#include <stdlib.h>


unsigned char rotate_left(unsigned char x, int n)
{
    return (x << n) | (x >> (8 - n));

}


int main(void) {
    unsigned char x = 0x61; 
    printf("Valor original: 0x%02X\n\n", x);
    // Teste 1: Rotate left de 1 bit 
    printf("Rotate Left (1 bit):  0x%02X\n", rotate_left(x, 1));
    // Teste 2: Rotate left de 2 bits
    printf("Rotate Left (2 bits): 0x%02X\n", rotate_left(x, 2));
    // Teste 3: Rotate left de 7 bits 
    printf("Rotate Left (7 bits): 0x%02X\n", rotate_left(x, 7));
    // Teste Extra: Rotate left de 8 bits
    printf("Rotate Left (8 bits): 0x%02X\n", rotate_left(x, 8));
    return 0;
}