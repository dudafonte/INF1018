#include <stdio.h>

void foo(int a[], int n);

int main(void)
{
    int a[] = {2,4,5,0,7};
    int n = 5;
    foo(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}