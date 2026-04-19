.globl filtro
filtro:
 
 pushq %rbp 
 movq  %rsp, %rbp 

cmpl %esi, %edi
jl  label_else

movl %edi, %eax
jmp label_fim

label_else:
movl $0, %eax

label_fim:
 leave
 ret