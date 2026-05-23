.text
.globl bemboba


bemboba:
    pushq   %rbp 
    movq    %rsp, %rbp
    
    subq    $32, %rsp 
    leaq    -16(%rbp), %rax 
    movq    %rax, -24(%rbp)
    movl    $0, -28(%rbp)
loop:
    cmpl    $4, -28(%rbp)
    jge     fora_loop

    movq    -24(%rbp), %rax 
    movl    %edi, (%rax)
    addq    $4, -24(%rbp)
    addl    $1, -28(%rbp)
    jmp     loop
fora_loop:
    leaq    -16(%rbp), %rdi 
    movl    $4, %esi 
    call addl 
    leave
    ret