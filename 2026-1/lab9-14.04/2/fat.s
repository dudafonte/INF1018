.globl fat
fat:
    pushq   %rbp 
    movq    %rsp, %rbp 
    pushq   %rbx

    movl    %edi, %ebx

    cmpl    $0, %edi 
    je      label_base 

    subl    $1, %edi 
    call    fat 

    imull   %ebx, %eax 
    jmp     label_fim 

label_base:
    movl    $1, %eax 

label_fim:
    popq    %rbx
    leave
    ret