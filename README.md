# Monty Interpreter

### General

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (just like Python). It relies on a unique stack, with specific instructions (known as opcodes) to manipulate it. This program is an interpreter for Monty ByteCodes files.


### Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- All your files should end with a new line
- Code follows the [Betty](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) [Style](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- The prototypes of all your functions should be included in your header file called `monty.h`
- Header file should be include guarded

### Compilation

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### Usage Example

`pall`: opcode that prints all the values on the stack, starting from the top of the stack

```
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
```

```
$ ./monty bytecodes/00.m
3
2
1
```

`pop`: opcode that removes the top element of the stack

```
$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
```

```
$ ./monty bytecodes/07.m 
3
2
1
2
1
1
```

### File Descriptions



### Monty's Program Flow



### Authors

[Kevin Paul Apostal](https://github.com/kevapostol)

[Ariana Bibiano](https://github.com/ariana124)
