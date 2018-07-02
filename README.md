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
  
The Corewar project is incredibly conplexed given our collective experience to date. We considered the following materials:
- [42 Project](./corewar.en.pdf)
- [Epitech Project](./images/corewar_en.pdf)
- [Corewar Cheat Sheet](./images/Corewar_Cheat_Sheet.pdf) (French).
  
A `champion` is written in `assembly` syntax. A `champion` is compiled by the `asm` (assembler), into a binary file. The compiled `champion` is then loaded into `corewar` (virtual machine) as a process, with other `champion`s.  
  
`corewar` will end after *some time* or when all the processes have died. The winner is the last `champion` to have been reported alive.  

An example `champion`:
```assembly
.name		"Celebration Funebre v0.99pl42"
.comment	"Jour J"

		ld   %0,r3
label:		zjmp %:avantdebut
		zjmp %0				# pour eviter ecrasement
						# de l'instruction suivante
code:		live %42			# 5
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		live %42			# 5
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		live %42			# 5
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		live %42			# 5
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		sti  r15,%0,r14			# 6
		zjmp %-200			# 3
		sti  r15,%0,r14			# 6
		zjmp %-200

avantdebut:	sti   r1,%:code,%1  # 		#7
		sti   r1,%:code,%15 # 		#7
		sti   r1,%:code,%29 # 		#7
		sti   r1,%:code,%43 # 		#7
		sti   r1,%:code,%57 # 		#7
		sti   r1,%:code,%71 # 		#7
init:		ld   %393216,r4		 	#7
		ld   %917504,r12		#7
		ld   %1,r11			#7
		ld   %6,r10			#7
debut:		live %42			#5
		sti  r4,%:label , %1		#7
		add  r4,r12,r4			#5
		sub  r10,r11,r10		#5
		zjmp %:init			#3
		fork %:debut
		live %3
level0:		fork %:level10
level11:	live %4
		fork %:level111

level110:	live %42
		ldi  %8, %:code, r15		#set des octets 9-12
		ld   %-186, r14			#=$A-6-8
		ld   %0,r2
		zjmp  %:label

level10:	live %42
		fork %:level100
level101:	live %42
		ldi  %4, %:code, r15 		#set des octets 5-8
		ld   %-190, r14			#=$A-6-4
		ld   %0,r2
		zjmp %:label

level111:	live %42
		ldi  %12, %:code, r15		#set des octets 13-16
		ld   %-182, r14			# $A -6 -12
		ld   %0,r2
		zjmp %:label

level100:	live %42
		ldi  %0, %:code, r15		#set des octets 1-4
		ld   %-194, r14			# $A -6 -0
		ld   %0,r2			#
		zjmp %:label			#
```
And subsequent `asm` compiled binary which is loadable into `corewar`:
```console
$> hexdump -C Gagnant.cor
00000000  00 ea 83 f3 43 65 6c 65  62 72 61 74 69 6f 6e 20  |....Celebration |
00000010  46 75 6e 65 62 72 65 20  76 30 2e 39 39 70 6c 34  |Funebre v0.99pl4|
00000020  32 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |2...............|
00000030  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000080  00 00 00 00 00 00 00 00  00 00 01 45 4a 6f 75 72  |...........EJour|
00000090  20 4a 00 00 00 00 00 00  00 00 00 00 00 00 00 00  | J..............|
000000a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000890  02 90 00 00 00 00 03 09  00 50 09 00 00 01 00 00  |.........P......|
000008a0  00 2a 0b 64 0f 00 00 0e  09 ff 38 01 00 00 00 2a  |.*.d......8....*|
000008b0  0b 64 0f 00 00 0e 09 ff  38 01 00 00 00 2a 0b 64  |.d......8....*.d|
000008c0  0f 00 00 0e 09 ff 38 01  00 00 00 2a 0b 64 0f 00  |......8....*.d..|
000008d0  00 0e 09 ff 38 0b 64 0f  00 00 0e 09 ff 38 0b 64  |....8.d......8.d|
000008e0  0f 00 00 0e 09 ff 38 0b  68 01 ff b6 00 01 0b 68  |......8.h......h|
000008f0  01 ff af 00 0f 0b 68 01  ff a8 00 1d 0b 68 01 ff  |......h......h..|
00000900  a1 00 2b 0b 68 01 ff 9a  00 39 0b 68 01 ff 93 00  |..+.h....9.h....|
00000910  47 02 90 00 06 00 00 04  02 90 00 0e 00 00 0c 02  |G...............|
00000920  90 00 00 00 01 0b 02 90  00 00 00 06 0a 01 00 00  |................|
00000930  00 2a 0b 68 04 ff 65 00  01 04 54 04 0c 04 05 54  |.*.h..e...T....T|
00000940  0a 0b 0a 09 ff ce 0c ff  e7 01 00 00 00 03 0c 00  |................|
00000950  28 01 00 00 00 04 0c 00  45 01 00 00 00 2a 0a a4  |(.......E....*..|
00000960  00 08 ff 3f 0f 02 90 ff  ff ff 46 0e 02 90 00 00  |...?......F.....|
00000970  00 00 02 09 ff 24 01 00  00 00 2a 0c 00 3d 01 00  |.....$....*..=..|
00000980  00 00 2a 0a a4 00 04 ff  1a 0f 02 90 ff ff ff 42  |..*............B|
00000990  0e 02 90 00 00 00 00 02  09 fe ff 01 00 00 00 2a  |...............*|
000009a0  0a a4 00 0c fe fd 0f 02  90 ff ff ff 4a 0e 02 90  |............J...|
000009b0  00 00 00 00 02 09 fe e2  01 00 00 00 2a 0a a4 00  |............*...|
000009c0  00 fe e0 0f 02 90 ff ff  ff 3e 0e 02 90 00 00 00  |.........>......|
000009d0  00 02 09 fe c5                                    |.....|
```

The program cannot leak. All errors must be handled carefully. In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions for the mandatory part are `open`, `read`, `lseek`, `write`, `close`, `malloc`, `realloc`, `free`, `perror`, `strerror` and `exit`. Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.
***
### Using the project
To compile, run `make`. This will compile two programs; **asm** and **corewar**.
##### asm  
Our overall bonuses for `asm` are:  
- The path at which the binary file is written to can be specified.
- Error handling in a `gcc` fashion, with errors, parsed data, and line numbers (with colour).  
  
For `usage`:
```console
$> ./asm
Usage: ./asm <sourcefile.s> [dest path]
```
As standard, `asm` must take as an argument a `champion` with a '.s' file extention. If the `champion` is valid, it must comiled and a compiled '.cor' binary must be placed in the same directory and with the same filename as the `assembly` file. For example:
```console
$> ls champion/
451.s
$> ./asm champion/451.s
Writing to champion/451.cor
$> ls champion/
451.cor 451.s
```
As a bonus feature, we allowed `asm` to take `dest path` as an argument to specify the destination of the compiled '.cor' binary. In the following example, we compile zork.s to the current directory.
```console
$> ls -l
total 2904
-rw-r--r--  1 Dav  staff     1856 29 Jun 12:38 Makefile
-rw-r--r--  1 Dav  staff        9 20 Jun 06:53 README.md
-rwxr-xr-x  1 Dav  staff    48124  2 Jul 20:22 asm
drwxr-xr-x  7 Dav  staff      224  2 Jul 20:22 assembler
-rw-r--r--  1 Dav  staff       32 20 Jun 06:53 author
drwxr-xr-x  4 Dav  staff      128  2 Jul 22:30 champion
-rwxr-xr-x  1 Dav  staff    58132  2 Jul 20:22 corewar
-rw-r--r--@ 1 Dav  staff  1363780 29 Jun 12:38 corewar.en.pdf
drwxr-xr-x  7 Dav  staff      224  2 Jul 20:22 libft
drwxr-xr-x  6 Dav  staff      192 29 Jun 12:38 resources
drwxr-xr-x  3 Dav  staff       96 29 Jun 12:38 shared
drwxr-xr-x  8 Dav  staff      256  2 Jul 20:22 virtual_machine
$> ./asm resources/champs/examples/zork.s .
Writing to ./zork.cor
$> ls -l
total 2912
-rw-r--r--  1 Dav  staff     1856 29 Jun 12:38 Makefile
-rw-r--r--  1 Dav  staff        9 20 Jun 06:53 README.md
-rwxr-xr-x  1 Dav  staff    48124  2 Jul 20:22 asm
drwxr-xr-x  7 Dav  staff      224  2 Jul 20:22 assembler
-rw-r--r--  1 Dav  staff       32 20 Jun 06:53 author
drwxr-xr-x  4 Dav  staff      128  2 Jul 22:30 champion
-rwxr-xr-x  1 Dav  staff    58132  2 Jul 20:22 corewar
-rw-r--r--@ 1 Dav  staff  1363780 29 Jun 12:38 corewar.en.pdf
drwxr-xr-x  7 Dav  staff      224  2 Jul 20:22 libft
drwxr-xr-x  6 Dav  staff      192 29 Jun 12:38 resources
drwxr-xr-x  3 Dav  staff       96 29 Jun 12:38 shared
drwxr-xr-x  8 Dav  staff      256  2 Jul 20:22 virtual_machine
-rw-r--r--  1 Dav  staff     2215  2 Jul 22:34 zork.cor
```
`asm` provides detailed error handling output in a similar fashion to `gcc`.
```console
$> ./asm champion/451.s
Error: Invalid number of params for this operation at line 4
	"		aff r1, r3"

Error: Label requested not declared at line 5
	"		sti r1, %:legal, %1"

Error: Invalid character after operation name at line 8
	"legal>:	live %1"

Error: Label requested not declared at line 9
	"		zjmp %:legal"
```
  
##### corewar
Our overall bonuses for `corewar` are:  
- `debug` An accidental visualizer, to illustrate each cycle as an animation.
- `-dump` illustrates the position of the program counter.
- When the debugger is activated, a sound is played when a process is killed by `corewar`.
- No `live` calls = no winners. Some `corewar` virtual machines arbitrarily choose a winner.
- `aff` output. The standard, is to display a value with a modulo of 256 applied. We decided to allow alternative methods to display the value inside a register. See `usage`  
  
For `usage`:
```console
$> ./corewar
_________                 ___       __
__  ____/___________________ |     / /_____ ________
_  /    _  __ \_  ___/  _ \_ | /| / /_  __ `/_  ___/
/ /___  / /_/ /  /   /  __/_ |/ |/ / / /_/ /_  /
\____/  \____/\/_/    \___/____/|__/  \___/ /_/
                               VIRTUAL MACHINE


USAGE
> ./corewar [-a | -d | -x | -X] [[-dump | -debug] nbr_cycles] [[-n number] champion1.cor] ...


FLAGS
-a      Aff (Character with 256 modulo applied).
-d      Aff (Displayed as decimal).
-x      Aff (Displayed as hexidecimal (lower case)).
-X      Aff (Displayed as hexidecimal (upper case)).

-n      Player number selection.
        Example: > ./corewar -n 42 tasos.cor -n 7 marti.cor
        Corewar will auto-assign where no selection is made.

-dump   Dump memory.
        Example: > ./corewar -dump 27 dav.cor federico.cor
        Here, Corewar will dump memory after 42 cycles.
        Corewar can only accept 1 -dump argument.

-debug  Debug Mode.
        Example: > ./corewar -debug 27 dav.cor federico.cor
        Dumps memory in animation mode for debug purposes.
        Corewar does not accept Bitcoin Cash LOL.
        Corewar can only accept 1 -debug argument.
```
`-dump` is a mandatory flag. We decided to illustrate the position of program counters in the memory dump:  
![-dump](./images/corewar_dump.png)  
  
We created a debugger, which developped unintentionally into a visualizer. Its syntax is the same as -dump and will start the visualization from that cycle. **Note**, each time a process is killed, a sound will be played.  
![-debug](./images/corewar_debug.gif)
  
##### champion
Within the scope of the project, we needed to submit one chammpion. There follows a seperate project, Corewar Champioinship. As such, we did not want to display our best `champion`s bcause we would loose our future competative edge.  
  
We made a `champion` named **451**. **451** was explicitly designed to beat **zork** in most circumstances.  
451:
```assembly
.name "451"
.comment "Unavailable For Legal Reasons"

		aff r1
		sti r1, %:legal, %1
		and r1, %0, r1

legal:	live %1
		zjmp %:legal
```
zork:
```assembly
.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
```
Sure, we did not use so much imagination here, but **451** usually wins against **zork**. In most situations, **451** says `live` last owing to being delayed by 2 cycles due to the functionless `aff` instruction:
```console
$> ./corewar zork.cor 451.cor
Player 2 (451) won
```
```console
$> ./corewar 451.cor zork.cor
Player 1 (451) won
```
