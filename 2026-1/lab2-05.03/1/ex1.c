#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}


int main (void) {
  // a.
  int p1 = 10000;
  // b.
  long int p2 = 10000;
  //c.
  short int p3 = 10000;
  // d.
  char p9 = 97;
  char p10 = 'a';
  // e.
  char p4[] = "7509";
  char p5 = 'A';
  char p6 = ' ';
  char p7 = '\n';
  char p8 = '$';

  dump(&p1, sizeof(p1));
  printf("\n");
  dump(&p2, sizeof(p2));
  printf("\n");
  dump(&p3, sizeof(p3));
  printf("\n");
  dump(&p4, sizeof(p4));
  printf("\n");
  dump(&p5, sizeof(p5));
  printf("\n");
  dump(&p6, sizeof(p6));
  printf("\n");
  dump(&p7, sizeof(p7));
  printf("\n");
  dump(&p8, sizeof(p8));
  printf("\n");
  dump(&p9, sizeof(p9));
  printf("\n");
  dump(&p10, sizeof(p10));
  return 0;
}