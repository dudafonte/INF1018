.globl boo 
boo:
    /* Dicionário  
    VAR     REG 
    *px     %rdi 
    n       %esi
    val     %edx
    */

    /* Prologo */ 
    pushq   %rbp
    movq    %rsp, %rbp 
    subq    $24, %rsp 
    movq    %rbx, -8(%rbp)
    movq    %r12, -16(%rbp)
    movq    %r13, -24(%rbp)

    movq    %rdi, %rbx 
    movl    %esi, %r12d 
    movl    %edx, %r13d 

WHILE:
    cmpl    $0, %r12d 
    je      FORA_WHILE

    movl    (%rbx), %edi
    movl    %r13d, %esi
    call    f
    movl    %eax, 4(%rbx)

    addq    $8, %rbx
    decl    %r12d 

    jmp WHILE

FORA_WHILE:
    movq      -8(%rbp), %rbx 
    movq      -16(%rbp), %r12 
    movq      -24(%rbp), %r13 
    leave 
    ret
