.globl sysint
sysint:

pushl %eax
movl 8(%esp), %eax

pushl %ebx
movl 16(%esp), %ebx

pushl %ecx
movl 24(%esp), %ecx

pushl %edx
movl 32(%esp), %edx

pushl %esi
movl 40(%esp), %esi

pushl %edi
movl $ret, %edi

pushl %ebp
movl %esp, %ebp

sysenter

ret:

popl %ebp
popl %edi
popl %esi
popl %edx
popl %ecx
popl %ebx
addl $4, %esp

ret
