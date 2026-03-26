#include <stdio.h>




union u1 
{
    int a;
    int b
};

union u2
{
    short a;
    int b;

}


int main(void)
{
    union u1 x;
    x.a = 10;
    x.b = 20;
    printf("x.a: %d\n", x.a);
    printf("x.b: %d\n", x.b);

    union u2 y;
    y.a = 30;
    y.b = 40;
    printf("y.a: %d\n", y.a);
    printf("y.b: %d\n", y.b);

    return 0;

}