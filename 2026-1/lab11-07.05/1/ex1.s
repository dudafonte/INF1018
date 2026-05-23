
.data 
msg: .string "numero: "
Sf: .string "%d"

.text
.globl novonum

novonum:
    pushq   %rbp 
    movq    %rsp, %rbp 
    subq    $16, %rsp 

    movq    $msg, %rdi 
    movl    $0, %eax 
    call    printf

    movq    $Sf, %rdi
    leaq    -4(%rbp), %rsi
    movl    $0, %eax 
    call    scanf

    movl    -4(%rbp), %eax 
    leave 
    ret 
