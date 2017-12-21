#include "monty.h"
/**
* check_no_arg_func - Check if arg is valid and call corresponding funciton
* @line_num: Number line of the arg in bytecode file
* @token_1: argument to check
* Return: O success, -1 if invalid command
*/
int check_no_arg_func(unsigned int line_num, char *token_1)
{
	int i;

	instruction_t no_arg_func[] = {
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
		/*	{"div", div},*/
			{"mul", mul},
			{NULL, NULL}
			};
	for (i = 0; no_arg_func[i].opcode != NULL; i++)
	{
		/*check if the command(token) is a valid command*/
		if (strcmp(token_1, no_arg_func[i].opcode) == 0)
		{
			/*call corresponding function for that command*/
			no_arg_func[i].f(&head, line_num);
			return (0);
		}
	}
	return (-1);
}
/**
* check_arg_func - checks if an arg is valid and call corresponding function
* @ln_num: Number line of the arg in bytecode file
* @tok_1: first argument to check
* @tok_2: second argument to check
* @buf: Pointer to string of commands from bytecode monty file
* @fp: Pointer to open monty file
*/
void check_arg_func(unsigned int ln_num,
		char *command, char *arg, char *buf, FILE *fp)
{
	int i, n;
	stack_t *stack = NULL;

	instruction_t arg_func[] = {
			{"push", push},
			{NULL, NULL}
			};
	for (i = 0; arg_func[i].opcode != NULL; i++)
	{
		/*check if tok_1, is a valid command */
		if (strcmp(command, arg_func[i].opcode) == 0)
		{
			/*check if the tok_2 is a valid arg for the command*/
			if (arg != NULL && isdigit(*arg) != 0)
			{

				n = atoi(arg);
				stack = create_stack(n, buf, fp);
				/*send stack to be pushed */
				arg_func[i].f(&stack, ln_num);

			}
			else/*invalid arg to command is given*/
			{
				printf("L%d: usage: push integer\n", ln_num);
				free(buf);
				fclose(fp);
				free_stack();
				exit(EXIT_FAILURE);
			}
		}
		else/*invalid command is given*/
		{
			free_stack();
			printf("L%d: unknown instruction %s\n", ln_num, command);
			free(buf);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
	}
}
