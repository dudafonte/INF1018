#include <stdio.h>
#include <math.h>

#define getsig(x)        ((x)>>31 & 1)
#define getexp(x)        ((x)>>23 & 0xff)
#define getfrac(x)       ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union {
  float f;
  unsigned int i;
} U;

float int2float(int n) {
    U u;
    unsigned int s, e, frac;
    unsigned int abs_n;

    if (n == 0) {
        u.i = 0;
        return u.f;
    }

    // bit de sinal
    s = (n < 0) ? 1 : 0;

    abs_n = (n < 0) ? (unsigned int)(-(n+1)) + 1 : (unsigned int)n;
    int E = 0;
    unsigned int tmp = abs_n;
    while (tmp > 1) {
        tmp >>= 1;
        E++;
    }
    // E eh o expoente real, exp armazenado=E+127
    e = E + 127;

    if (E <= 23)
        frac = (abs_n << (23 - E)) & 0x7fffff;
    else
        frac = (abs_n >> (E - 23)) & 0x7fffff;

    u.i = makefloat(s, e, frac);
    return u.f;
}


int main() {
   int i;

   printf("\n******** int2float ****************\n");
   i = 0;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 1;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -1;  
   printf(" %d -> %10.4f\n", i, int2float(i));
   i = 0x7fffffff;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -i;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   return 0;
}