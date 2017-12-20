#ifndef _MONTY_H_ 
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
stack_t *head;
void open_file(char *monty_file);
void read_and_tokenize(FILE *fp);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **head, unsigned int line_num);
stack_t *create_stack(int n, char *buf, FILE *fp);
int check_no_arg_func(unsigned int line_num, char *token_1);
void check_arg_func(unsigned int ln_num, char *tok_1, char *tok_2, char *buf, FILE *fp);
#endif
