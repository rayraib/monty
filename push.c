#include "monty.h"
/**
* push - pushes or adds a new element to the stack
* @n: new element to add
*/
void push(stack_t **stack, unsigned int line_num)
{
	extern stack_t *head;

	(*stack)->next = head;
	(*stack)->prev = NULL;
	head = (*stack);
}
/**
* pall - prints all the values on the stack, starting from top
*/
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
