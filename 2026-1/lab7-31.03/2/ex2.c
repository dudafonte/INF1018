#include <stdio.h>

char S2[] = {65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0};

int main (void) {

  for (char *pc=S2; *pc != '\0'; pc++)
  {
    if (*pc == 123 || *pc == 125)
    {
        continue;
    }
    printf("%c", *pc);
  }
  printf("\n");
  return 0;
}


