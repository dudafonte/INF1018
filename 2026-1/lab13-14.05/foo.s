/*
int foo (int x) {
  return x+1;
}
*/

.text 
.globl foo
foo:
    pushq   %rbp
    movq    %rsp, %rbp
    #subq    $..., %rsp 

    movl    %edi, %eax 
    incl    %eax 

    leave
    ret