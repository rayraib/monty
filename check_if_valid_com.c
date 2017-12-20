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
			{"pint", pint},
			{"pop", pop},
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
void check_arg_func(unsigned int ln_num, char *tok_1, char *tok_2, char *buf, FILE *fp)
{
	int i, n;
	stack_t *stack;
	
	instruction_t arg_func[] = {
			{"push", push},
			{NULL, NULL}
			};
	stack = NULL;
	for (i = 0; arg_func[i].opcode != NULL; i++)
	{
		if (strcmp(tok_1, arg_func[i].opcode) == 0)
		{
			if (tok_2 != NULL && isdigit(*tok_2) != 0)
			{
				
				n = atoi(tok_2);
				stack = create_stack(n, buf, fp);
				arg_func[i].f(&stack, ln_num);

			}
			else	
			{
				free(buf);
				fclose(fp);
				free_stack();
				printf("L%d: usage: push integer\n", ln_num);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			free(buf);
			fclose(fp);
			free_stack();
			printf("L%d: unknown instruction %s\n", ln_num, tok_2);
			exit(EXIT_FAILURE);
		}
	}
}
