#include <stdio.h>

void f1(void);
void f2(void);

void f1(void)
{
    puts("Estou em F1");
}

int main(void)
{
    for (int i=0; i < 10; i++)
    {
        f1();
        f2();
        f1();
        f2();
    }
    return 0;
}


void f2(void)
{
    puts("Estou em F2");
}