#include <stdio.h>
#include <stdlib.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

struct X {
  int a;
  short b;
  int c;
} x;


int main(void)
{
    struct X x1;
    printf("Tamanho de X: %ld\n", sizeof(x1));
    printf("\nInfos da struct X:\n");
    dump(&x1, sizeof(x1));

    return 0;
}