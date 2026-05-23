.globl add 
add:

    movl    $0, %eax      # int a = 0

WHILE:
    cmpq    $0, %rdi
    je      FORA_WHILE
 
    add     (%rdi), %eax 
    movq    8(%rdi), %rdi

    jmp WHILE

FORA_WHILE:
    ret 



