#include "monty.h"
/**
* sub - subtracts the top element of the stack from the second top element
* @head: Pointer to the top element of the stack
* @line_num: Number line of the command in monty file
*/
void sub(stack_t **head, unsigned int line_num)
{
	int n = 0;
	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	n = (*head)->next->n - (*head)->n;
	(*head) = (*head)->next;
	free ((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = n;
}
