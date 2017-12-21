#include "monty.h"
/**
* pchar - prints teh char at the top of the stack
* @head: Pointer to a pointer that points to the stack link
* @line_num: Number line of the command pchar in the monty file
*/
void pchar(stack_t **head, unsigned int line_num)
{
	int val;

	if (head == NULL || (*head) == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	val = (*head)->n;
	if (val >= 65 && val <= 90)
	{
		printf("%c\n", val);
	}
	else if (val >= 97 && val <= 122)
	{
		printf("%c\n", val);
	}
	else
	{
		printf("L%d: can't pchar, value out of range\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
}
