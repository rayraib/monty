# Monty 
### Synopsis
#### Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
*Monty Bytecode File example:*
```
vagrant@vagrant-ubuntu-trusty-64:~/holbertonschool-low_level_programming/0x18-stacks_queues_
lifo_fifo$. Stack (LIFO) & queue (FIFO)$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
-----------------------

### Environment
Tested on `Ubuntu 14.04 LTS` via Vagrant in VirtualBox.
### Repo Contents\functions
**monty @ 1cde95f**: Submodule containing the C source files.

| Files | Description |
| --------- | ----------- |
|**main.c**| Entry point to the program. Checks if there valid arguments of the executable and a Monty Bytecode file.|
|**open_and_read.c**| Opens the Monty file and reads its contents one line at a time to a buffer.|
|**check_if_valid_com.c**| Contains the functions: Checks if the command in each line is a valid command that can be executed. If it is, it calls corresponding fuction to execute the command|
|**push_and_pull.c**| Contains the stack operation `push` and `pall` functions.|
|**stacks_ops.c**| Contains the stack operations `pint`, `pop`, `swap`, `nop`.|
|**stack_op_maths.c**| Contains the math operations, `add`, `sub`, `mul`, `div_stack`, `mod`.|
|**stack_op_string.c**| Contains string operations, `pchar`, `pstr`, `rotl`, `rotr`.|
|**free_link_list.c**| Frees the linked list stack.|
|**monty.h**| Header file for the repository.|

### How to install
To install, clone the repository to a directory, compile, then run the executable with a Monty Bytecode file.
https://github.com/rayraib/monty/
### Compilation
Compile the code with the following flags: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

*Usage Example:*
```
vagrant@vagrant-ubuntu-trusty-64:~/holbertonschool-low_level_programming/0x18-stacks_queues_
lifo_fifo$ ./monty bytecodes/00.m
```

