.globl add2
add2:

IF:
    cmpq    $0, %rdi 
    jne     ELSE
    movl    $0, %eax 
    ret
    
ELSE:
    pushq   %rdi 
    movq    8(%rdi), %rdi 
    call    add2 
    popq    %rdi 
    addl    (%rdi), %eax 
    ret
