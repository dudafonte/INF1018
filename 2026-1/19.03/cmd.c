#include <stdio.h>

int main(int argc, char *argv[])
{
    // qtd de argumentos
    printf("Quantidade de argumentos: argc = %d\n", argc);

    // valor (quais são) dos argumentos
    for(int i =0; i <argc; i++)
    {
        printf("Argumento %d: argv[%d] = %s\n", i, i, argv[i]);
    }
    return 0;
    
}