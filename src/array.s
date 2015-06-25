.PRINTF_I:
	.string "%i"
.PRINTF_I_N:
	.string "%i\n"
.PRINTF_F:
	.string "%f"
.PRINTF_F_N:
	.string "%f\n"
.text
.globl main
	.type main, @function
main:
pushl %ebp
movl %esp, %ebp
movl %esp, %ecx
subl $48, %esp
movl $1, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)  
__CG__label0:
movl $10, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %ebx
cmpl %ebx, %eax
ja __CG__label1
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
movl $1, %ebx
subl %ebx, %eax
movl $4, %ebx
imull %ebx, %eax
movl $-48, %edi
addl %eax, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
inc %eax
movl %eax, -0(%esi)
jmp __CG__label0
__CG__label1:
movl $1, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)  
__CG__label2:
movl $10, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %ebx
cmpl %ebx, %eax
ja __CG__label3
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
movl $1, %ebx
subl %ebx, %eax
movl $4, %ebx
imull %ebx, %eax
movl $-48, %edi
addl %eax, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
inc %eax
movl %eax, -0(%esi)
jmp __CG__label2
__CG__label3:
addl $48, %esp
leave
ret
