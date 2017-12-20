#include "monty.h"
/**
* push - pushes or adds a new element to the stack
* @stack: pointer to new elment to add on to stack
* @line_num: Number line of the command on bytecode monty file
*/
void push(stack_t **stack, unsigned int line_num)
{
	(void) line_num;

	(*stack)->next = head;
	(*stack)->prev = NULL;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack);
	head = (*stack);
}
/**
* pall - prints all the values on the stack, starting from top
* @head: Pointer to first element on the stack
* @line_num: Number line of the command in the monty file
*/
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void) line_num;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
