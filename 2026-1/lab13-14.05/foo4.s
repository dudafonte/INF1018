/*
int foo (int x) {
  return add(x);
}
*/

.text 
.globl foo4 
foo4:
    # salvar o RA da chamadora e criar o RA 
    pushq   %rbp 
    movq    %rsp, %rbp 

    # salvar callee-saved 

    # preparar os parâmetros
    # já estão no edi 
    call add 

    # restaurar o callee-saved 
    # remover RA 
    leave 

    # retornar 
    ret 