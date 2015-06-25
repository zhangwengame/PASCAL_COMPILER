.PRINTF_I:
	.string "%i"
.PRINTF_I_N:
	.string "%i\n"
.PRINTF_F:
	.string "%f"
.PRINTF_F_N:
	.string "%f\n"
.text
hh: 
subl $8, %esp
movl $10, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $4, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $11, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
movl (%esi), %eax
movl %eax, %esi
movl (%esi), %eax
movl %eax, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $12, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
movl (%esi), %eax
movl %eax, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
addl $8, %esp
ret
gg: 
subl $8, %esp
pushl %eax
movl $4, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $1, %eax	# calculate int ExpConst 
pushl %eax
popl %ebx
popl %eax
addl %ebx, %eax
pushl %eax
pushl %ecx
movl %esp, %ecx
call hh
popl %ecx
popl %eax
popl %eax
pushl %eax
movl $8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_I
call printf
addl $8, %esp
popa
addl $8, %esp
ret
ff: 
subl $8, %esp
pushl %eax
movl $4, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $1, %eax	# calculate int ExpConst 
pushl %eax
popl %ebx
popl %eax
addl %ebx, %eax
pushl %eax
pushl %ecx
movl %esp, %ecx
call gg
popl %ecx
popl %eax
popl %eax
pushl %eax
movl $8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_I
call printf
addl $8, %esp
popa
addl $8, %esp
ret
.globl main
	.type main, @function
main:
pushl %ebp
movl %esp, %ebp
movl %esp, %ecx
subl $8, %esp
pushl %eax
movl $1, %eax	# calculate int ExpConst 
pushl %eax
pushl %ecx
movl %esp, %ecx
call ff
popl %ecx
popl %eax
popl %eax
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_I
call printf
addl $8, %esp
popa
addl $8, %esp
leave
ret
