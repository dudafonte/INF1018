#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int string2num (char *s) {
  int a = 0;
  for (; *s; s++)
    a = a*10 + (*s - '0');
  return a;
}


int string2numBases(char *s, int base)
{
    int a = 0;
    for (; *s; s++)
        a = a*base + (*s - '0');
    return a;
}


int string2numBases2(char *s, int base)
{
    int a = 0;
    int digito;
    for (; *s; s++)
    {
        if (isdigit(*s))
        {
            digito = *s - '0';
        }
        else if (isalpha(*s))
        {
            digito = tolower(*s) - 'a' + 10;
        }
        a = a * base + digito;
    }
    return a;
}



int main (void) {
  printf("\n==> %d\n", string2num("1234"));
  printf("==> %d\n", string2num("1234") + 1);
  printf("==> %d\n", string2num("1234") + string2num("1"));

  printf("\n==> %d\n", string2numBases("777", 8));
  printf("==> %d\n", string2numBases("001", 2));
  printf("==> %d\n", string2numBases("010", 2));
  printf("==> %d\n", string2numBases("011", 2));
  printf("==> %d\n", string2numBases("100", 2));
  printf("==> %d\n", string2numBases("101", 2));

  printf("\n==> %d\n", string2numBases2("1a", 16));
  printf("==> %d\n", string2numBases2("a09b", 16));
  printf("==> %d\n", string2numBases2("z09b", 36));

  return 0;
}