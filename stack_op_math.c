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
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = n;
}
/**
* mul - multiplies the second top element by top element of the stack
* @head: Pointer to the top element of the stack
* @line_num: Number line of the command in monty file
*/
void mul(stack_t **head, unsigned int line_num)
{
	int n = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	n = (*head)->n * (*head)->next->n;
	(*head) = (*head)->next;
	(*head)->n = n;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
* add - adds the top two elements of the stack
* @head: Pointer to the top of teh element of the stack
* @line_num: Line number of the command in monty bytecode file
*/
void add(stack_t **head, unsigned int line_num)
{
	int n = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	n = (*head)->n + (*head)->next->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = n;
}
/**
* div_stack - divides the top elements of the stack
* @head: Pointer to the top of teh element of the stack
* @line_num: Line number of the command in monty bytecode file
*/
void div_stack(stack_t **head, unsigned int line_num)
{
	int n = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	n = (*head)->next->n / (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = n;
}
/**
* mod - computes the rest of division of the second element by first element
* @head: Pointer to the top of teh element of the stack
* @line_num: Line number of the command in monty bytecode file
*/
void mod(stack_t **head, unsigned int line_num)
{
	int n = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	n = (*head)->next->n % (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = n;
}
