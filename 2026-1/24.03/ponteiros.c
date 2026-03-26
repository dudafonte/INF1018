#include <stdio.h>



int main(void)
{
    char *pChar;
    short int *pShort;
    int *pInt;
    long int *pLong;
    float *pFloat;
    double *pDouble;
    int k;

    pChar = (char *)0x1000;
    pShort = (short int *)0x1000;
    pInt = (int *)0x1000;
    pLong = (long int *)0x1000;
    pFloat = (float *)0x1000;
    pDouble = (double *)0x1000;

    k = 2;
    printf("pChar:   %p - %p\n", pChar, pChar + k);
    printf("pShort:  %p - %p\n", pShort, pShort + k);
    printf("pInt:    %p - %p\n", pInt, pInt + k);
    printf("pLong:   %p - %p\n", pLong, pLong + k);
    printf("pFloat:  %p - %p\n", pFloat, pFloat + k);
    printf("pDouble: %p - %p\n", pDouble, pDouble + k);

}