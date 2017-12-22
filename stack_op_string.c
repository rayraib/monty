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
/**
* pstr - Prints the string starting at the top of the stack.
* @head: Pointer to a pointer that ponts to the stack
* @line_num: Number line of the command pstr in the monty file
*/
void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	int val;
	(void) line_num;

	if (head == NULL || (*head) == NULL)
	{
		printf("\n");
	}
	else
	{
		tmp = *head;
		while (tmp != NULL && tmp->n != 0)
		{
			val = tmp->n;
			if (val >= 65 && val <= 90)
			{
				putchar(val);
				tmp = tmp->next;
			}
			else if (val >= 97 && val <= 122)
			{
				putchar(val);
				tmp = tmp->next;
			}
			else
			{
				break;
			}
		}
		putchar('\n');
	}
}
/**
* rotl - rotates stack to the top
* @head: Pointer to a pointer that points to the stack
* @line_num: Number line of the command rotl in the monty file
*/
void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void) line_num;

	if (head != NULL && (*head) != NULL && (*head)->next != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		(*head) = (*head)->next;
		tmp->next = (*head)->prev;
		(*head)->prev = NULL;
		tmp->next->next  = NULL;
		tmp->next->prev = tmp;
	}
}
