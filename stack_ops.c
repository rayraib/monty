#include "monty.h"
/**
* pint - Prints the value at the top of the stack
* @head: Pointer to the stack/top of the stack
* @line_num: Line number of the command in monty bytecode file
*/
void pint(stack_t **head, unsigned int line_num)
{
	if (head == NULL || (*head) == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
* pop - Remove top element from stack
* @head: Pointer to the top of element of stack
* @line_num: Line number of the command in monty bytecode file
*/
void pop(stack_t **head, unsigned int line_num)
{
	if (head == NULL || (*head) == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		(*head) = NULL;
	}
	else
	{
		(*head) = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}
/**
* swap - swaps the top two elements of the stack
* @head: Pointer to the top of teh element of the stack
* @line_num: Line number of the command in monty bytecode file
*/
void swap(stack_t **head, unsigned int line_num)
{
	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	(*head)->prev->next = (*head)->next;
	(*head)->prev->prev = (*head);
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	if ((*head)->next->next != NULL)
		(*head)->next->next->prev = (*head)->next;
}
/**
* nop - does nothing
* @head: Pointer to the top of teh element of the stack
* @line_num: Line number of the command in monty bytecode file
*/
void nop(stack_t **head, unsigned int line_num)
{
	(void) head;
	(void) line_num;
}
