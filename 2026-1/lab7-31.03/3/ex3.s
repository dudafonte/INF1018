.data
Sf:  .string "%d\n"

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

  movl     $1, %ebx        /* i = 1 (usando ebx para a variável local) */

L1:
  cmpl     $10, %ebx       /* Compara i com 10 */
  jg       L2              /* Se i > 10, sai do loop (jump if greater) */

  movl     %ebx, %eax      /* eax = i */
  imull    %eax, %eax      /* eax = eax * eax (calcula o quadrado) */

  /*************************************************************/
  /* Trecho para imprimir o valor de %eax                      */
  movq     $Sf, %rdi       /* 1º parâmetro: string de formato */
  movl     %eax, %esi      /* 2º parâmetro: o valor do quadrado */
  movl     $0, %eax        /* Preparação para printf */
  call     printf          /* printf("%d\n", quadrado) */
  /*************************************************************/

  addl     $1, %ebx        /* i++ */
  jmp      L1              /* Volta para o início do loop */

L2:  
/***************************************************************/
/* Finalização - Não altere                                    */
  movq     $0, %rax        /* valor de retorno 0 */
  movq     -16(%rbp), %r12 /* recupera r12 */
  movq     -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/