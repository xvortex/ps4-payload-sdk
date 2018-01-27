.intel_syntax noprefix

.extern __error

#If your assembler complains about the following uncommented line change it to:
#.section .sc_rop,"w"
.section .sc_rop,"w"
  syscall_rop: .quad 0

.text

.globl syscall
syscall:
	xor rax, rax

.globl syscall_macro
syscall_macro:
	call syscall_rop[rip]
	jb _error
	ret

_error:
  cmp qword ptr __error[rip], 0
  jz _end
  push rax
  call __error[rip]
  pop rcx
  mov [rax], ecx
  movq rax, -1
  movq rdx, -1

_end:
  ret
