#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        int quadrado = i * i;
        printf("%d^%d: %d\n", i, i, quadrado);
    }
    return 0;
}