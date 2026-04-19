.globl foo
foo:
    /*prologo */
    pushq   %rbp
    movq    %rsp, %rbp 
    pushq   %rbx 
    pushq   %r12 
    pushq   %r13 
    pushq   %r14 

    /*inicio*/
    movq    %rdi, %r14 
    movl    %esi, %r13d 
    movl    $0, %ebx 
    movl    $0, %r12d

L1:
    cmpl    %r13d, %r12d
    jge L_fim 

    movl    (%r14, %r12, 4), %eax 
    addl    %eax, %ebx

    cmpl    $0, %eax
    jne L_prox

    movl    %ebx, (%r14, %r12, 4)
    movl    $0, %ebx

L_prox:
    addl    $1, %r12d 
    jmp L1 

L_fim:
    popq    %r14 
    popq    %r13 
    popq    %r12 
    popq    %rbx 
    leave
    ret 
