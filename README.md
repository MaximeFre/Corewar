# Corewar
### Score 125/100
##### Mandatory
100/100
##### Bonus
25/25
***
### Challenge
To create a `corewar` (virtual machine), `asm` (assembler) and `champion` (fighting program).  
Four-person group project. `corewar` completed by [myself](https://github.com/davhojt) and [ffloris](https://github.com/fedefloris). `asm` completed by [mfiguera](https://github.com/mfigueras11) and [akaseris](https://github.com/akaseris).  
  
A `champion` is written in `assembly` syntax. A `champion` is compiled by the `asm` (assembler), into a binary file. The compiled `champion` is then loaded into `corewar` (virtual machine) as a process, with other `champion`s.  
  
```assembly
.name "Death"
.comment "Fork"
.extend

	st	r1, :l1+1
	st	r1, :l2+1
	st	r1, :l3+1
	st	r1, :l4+1
	st	r1, :golive+1
	st	r1, :live+1
	xor	r2,r2,r2
	fork	%:f1
	ld	%-15, r3
	ld	%1, r4
loop:	add	r3, r4, r3
	zjmp	%:golive
	xor	r5, r5, r5
	zjmp	%:loop
golive:	live	%1
	ld	%-25, r3
	ld	%1, r4
lock:	add	r3, r4, r3
	zjmp	%:nolock
	xor	r5, r5, r5
	zjmp	%:lock
nolock:
	xor	r1, r1, r1
	add	r1, r1, r1
	.code	00 00 00
live:	live	%1


f1:	fork	%:f2
f2:	fork	%:f3
f3:	fork	%:f4
f4:	fork	%:f5
f5:	fork	%:f6
f6:	fork	%:f7
f7:	fork	%:f8
f8:	fork	%:f9
f9:	fork	%:f10
f10:

l1:	live	%1
l2:	live	%1
l3:	live	%1
l4:	live	%1
	zjmp	%:l1
```
  
The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions for the mandatory part are `open`, `read`, `lseek`, `write`, `close`, `malloc`, `realloc`, `free`, `perror`, `strerror` and `exit`. Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.
***
### Using the project
