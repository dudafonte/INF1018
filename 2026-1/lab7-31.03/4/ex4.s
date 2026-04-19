.data
nums: .int 65, -105, 111, 34
fmt:  .string "soma = %d\n"

.text
.globl main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

  movl $0, %ebx    # ebx (soma = 0)
  movl $0, %ecx    # ecx (i = 0)

L1:
  cmpl $4, %ecx    # Compara i com 4
  jge L2           # Se i >= 4, sai do loop

  # Cálculo do endereço e acesso: nums[i]
  # Usamos movslq para estender o índice i (32 bits) para 64 bits (rcx)
  movslq %ecx, %rax
  
  # Pegamos o valor em nums + (rax * 4) e somamos em ebx (s)
  # A escala é 4 porque sizeof(int) = 4
  addl nums(,%rax,4), %ebx 

  incl %ecx        # i++
  jmp L1           # Volta para o início do loop

L2:
  # Preparação para o printf("soma = %d\n", s)
  movq $fmt, %rdi  # Primeiro argumento: string de formato
  movl %ebx, %esi  # Segundo argumento: o valor da soma (s)
  movl $0, %eax    # Limpa eax (padrão para funções variádicas como printf)
  call printf

/***************************************************************/
/* Finalização                                                 */
  movq $0, %rax    # valor de retorno 0
  movq -16(%rbp), %r12
  movq -8(%rbp), %rbx
  leave
  ret
/***************************************************************/