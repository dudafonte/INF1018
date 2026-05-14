// includes padrão
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>



// minhas variávies globais
// unsigned char codigo[] = {
//     0x55,                       //pushq
//     0x48, 0x89, 0xe5,           // mov    %rsp,%rbp
//     0x89, 0xf8,                 // mov    %edi,%eax
//     0xff, 0xc0,                 // inc    %eax
//     0xc9,                       // leave
//     0xc3                        // ret
// };

unsigned char codigo[] = {
   0x55,                           // push   %rbp
   0x48, 0x89, 0xe5,               // mov    %rsp,%rbp
   0xe8, 0x00, 0x00, 0x00, 0x00,   // call   9 <foo4+0x9>
   0xc9,                           // leave
   0xc3,                           // ret
};

// meus includes 

// minhas constantes e macros 
#define PAGE_START(P) ((intptr_t)(P)&~(pagesize-1))
#define PAGE_END(P) (((intptr_t)(P)+pagesize-1)&~(pagesize-1))

// meus protótipos de funções 
int bar(int x);
int execpage(void *ptr, size_t len);

// meus tipos 
typedef int (*funcp) (int x);
typedef unsigned int uint32;

int add (int x) {
  return x+1;
}

int bar(int x)
{
    return x + 1;
}

int main()
{
    int a = 5;
    int b;
    funcp f;         // f é ponteiro para função

    if (execpage(codigo, sizeof(codigo)) == -1)
    {
        perror("execpage");
        return 1;
    }

    b = bar(a);
    printf("bar(%d) = %d\n", a, b);

    f = bar;                        // f aponta para a função bar
    b = f(a);                       // chama a função através do ponteiro
    printf("f(%d) = %d\n", a, b);
    
    int offset;
    offset = (long)add - ((long)codigo+9);       // funcao - rip;
    *(int*)(codigo+5) = offset;

    f = (funcp)codigo;              // f aponta para o código de memória
    b = f(a);                       // chama a função através do ponteiro
    printf("f(%d) = %d\n", a, b);

    return 0;
}

int execpage(void *ptr, size_t len) {
	int ret;

	const long pagesize = sysconf(_SC_PAGE_SIZE);
	if (pagesize == -1)
		return -1;

	ret = mprotect((void *)PAGE_START(ptr),
		 PAGE_END((intptr_t)ptr + len) - PAGE_START(ptr),
		 PROT_READ | PROT_WRITE | PROT_EXEC);
	if (ret == -1)
		return -1;

	return 0;
}

#undef PAGE_START
#undef PAGE_END