#include "monty.h"
/**
* check_no_arg_func - Check if arg is valid and call corresponding funciton
* @line_num: Number line of the arg in bytecode file
* Return: O success, -1 if invalid command
*/
int check_no_arg_func(unsigned int line_num, char *token_1)
{
	int i;
	instruction_t no_arg_func[] = {
			{"pall", pall},
			{NULL, NULL}
			};
	for (i = 0; no_arg_func[i].opcode != NULL; i++)
	{
		if (strcmp(token_1, no_arg_func[i].opcode) == 0)
		{
			no_arg_func[i].f(&head, line_num);
			return (0);
		}
	}
	return (-1);
}
/**
* check_arg_func - checks if an arg is valid and call corresponding function
* @line_num: Number line of the arg in bytecode file
* @token_1: first argument to check
* @token_2: second argument to check
*/
void check_arg_func(unsigned int line_num, char *token_1, char *token_2)
{
	int i, n;
	stack_t *stack = NULL;
	instruction_t arg_func[] ={
			{"push", push},
			{NULL, NULL}
	};

	for (i = 0; arg_func[i].opcode != NULL; i++)
	{
		if (strcmp(token_1, arg_func[i].opcode) == 0)
		{
			if (token_2 != NULL && isdigit(*token_2) != 0)
			{
				n = atoi(token_2);
				stack = create_stack(n);
				arg_func[i].f(&stack, line_num);
			}
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_num, token_2);
			exit(EXIT_FAILURE);
		}
	}
}
