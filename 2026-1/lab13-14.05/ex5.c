#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

typedef int (*funcp)(int x);

#define PAGE_START(P) ((intptr_t)(P)&~(pagesize-1))
#define PAGE_END(P)   (((intptr_t)(P)+pagesize-1)&~(pagesize-1))

unsigned char codigo[] = {
    0x55,                           // push   %rbp
    0x48, 0x89, 0xe5,               // mov    %rsp,%rbp
    0xe8, 0x00, 0x00, 0x00, 0x00,   // call   add (offset a corrigir)
    0xc9,                           // leave
    0xc3                            // ret
};

int add(int x) {
    return x + 1;
}

int execpage(void *ptr, size_t len) {
    const long pagesize = sysconf(_SC_PAGE_SIZE);
    if (pagesize == -1) return -1;
    return mprotect((void *)PAGE_START(ptr),
        PAGE_END((intptr_t)ptr + len) - PAGE_START(ptr),
        PROT_READ | PROT_WRITE | PROT_EXEC);
}

#undef PAGE_START
#undef PAGE_END

int main() {
    int i;
    funcp f;

    if (execpage(codigo, sizeof(codigo)) == -1) {
        perror("execpage");
        return 1;
    }

    int offset = (long)add - ((long)codigo + 9);
    *(int*)(codigo + 5) = offset;

    f = (funcp)codigo;
    i = (*f)(10);
    printf("f(10) = %d\n", i); 

    return 0;
}