.text 
.globl map2 

map2:
     pushq      %rbp 
     movq       %rsp, %rbp 
     subq       $32, %rsp 
     movq       %rbx, -8(%rbp)
     movq       %r12, -16(%rbp)
     movq       %r13, -24(%rbp)
     movq       %r14, -32(%rbp)

     # salva param em registradores callee-save 
     movq       %rdi, %rbx 
     movq       %rsi, %r12 
     movl       %edx, %r13d

     movl       $0, %r14d    # i = 0

WHILE:
      cmpl     %r13d, %r14d
      jge      FORA_WHILE 

      movl     %r14d, %eax
      movl     (%rbx, %rax, 4), %edi 
      movl     $0, %eax 
      call f 

      movl      %r14d, %ecx
      movl      %eax, (%r12, %rcx, 4)

      addl      $1, %r14d 
      jmp WHILE 

FORA_WHILE:
      movq      -8(%rbp), %rbx 
      movq      -16(%rbp), %r12 
      movq      -24(%rbp), %r13 
      movq      -32(%rbp), %r14
      leave
      ret  

