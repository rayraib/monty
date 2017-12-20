#include "monty.h"
/**
* push - pushes or adds a new element to the stack
* @stack: pointer to the stack or top of the linked list 
* @line_num: Number line of the command in the monty bytecode file
*/
void push(stack_t **stack, unsigned int line_num)
{
	extern stack_t *head;
	(void) line_num;

	(*stack)->next = head;
	(*stack)->prev = NULL;
	head = (*stack);
}
/**
* pall - prints all the values on the stack, starting from top
* @head: Pointer to the head node of the link or the stack
* @line_num: Number line for the command in the monty bytecode file
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
