#include "monty.h"
/**
* check_cmd_no_arg - Check if arg is valid and call corresponding funciton
* @line_num: Number line of the arg in bytecode file
* @token_1: argument to check
* Return: O success, -1 if invalid command
*/
int check_cmd_no_arg(unsigned int line_num, char *token_1)
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
* @command: first argument to check
* @arg: second argument to check
* @buf: Pointer to string of commands from bytecode monty file
* @fp: Pointer to open monty file
*/
void check_cmd_arg(unsigned int ln_num,
		char *command, char *arg, char *buf, FILE *fp)
{
	int i;
	stack_t *stack = NULL;

	instruction_t arg_func[] = {
			{"push", push},
			{NULL, NULL}
			};
	for (i = 0; arg_func[i].opcode != NULL; i++)
	{
		/*check if command is a valid command */
		if (strcmp(command, arg_func[i].opcode) == 0)
		{
			stack = check_int_arg(arg, buf, fp);
			if (stack != NULL)
				arg_func[i].f(&stack, ln_num);
			else/*invalid arg to command is given*/
				invalid_cmd_errmsg(command, ln_num, buf, fp);
		}
		else/*invalid command is given*/
			invalid_cmd_errmsg(command, ln_num, buf, fp);
	}
}
/**
* invalid_cmd_errmsg - Frees buffer, close open file and print error msg
* @cmd: Invalid command to print error for
* @ln_num: Number line of the command in bytecode monty file
* @buf: Pointer to the command string
* @fp: FILE type pointer to the open monty file
*/
void invalid_cmd_errmsg(char *cmd, unsigned int ln_num, char *buf, FILE *fp)
{
	if (strcmp(cmd, "push") == 0)
	{
		printf("L%d: usage: push integer\n", ln_num);
		free(buf);
		fclose(fp);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("L%d: unknown instruction %s\n", ln_num, cmd);
	free_stack();
	free(buf);
	fclose(fp);
	exit(EXIT_FAILURE);
}
/**
* check_int_arg - checks if all the chars of the arg are int
* @arg: Argument to check for ints
* @buf: Pointer to where the argument is was initially stored
* @fp: Pointer to an open monty file with all commands and args
* Return: Pointer to new node with the arg value, NULL if failure
*/
stack_t *check_int_arg(char *arg, char *buf, FILE *fp)
{
	int n, i, is_neg = 0;
	stack_t *stack;

	if (arg != NULL && arg[0] == '-')
	{
		is_neg = -1;
		arg++;
	}
	if (arg != NULL && isdigit(*arg) != 0)
	{
		for (i = 0; arg[i] != '\0'; i++)
		{
			if (isdigit(arg[i]) == 0)
				return (NULL);
		}
		n = atoi(arg);
		if (is_neg == -1)
			n *= -1;
		stack = create_stack(n, buf, fp);
		return (stack);
	}
	return (NULL);
}
