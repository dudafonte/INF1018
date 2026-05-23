#include <stdio.h>

typedef union {
    float f;
    unsigned int i;
} U;

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

float float2(float f) {
    U u;
    u.f = f;

    unsigned int s = getsig(u.i);
    unsigned int e = getexp(u.i);
    unsigned int frac = getfrac(u.i);

    e = e + 1;

    u.i = makefloat(s, e, frac);
    return u.f;
}

int main() {
    printf("%f\n", float2(1.0f));   // 2.0
    printf("%f\n", float2(2.5f));   // 5.0
    printf("%f\n", float2(-3.0f));  // -6.0
    return 0;
}