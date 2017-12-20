#include "monty.h" 
/**
* open_file - opens a file to read
* @monty_file: file to open
*/
void open_file(char *monty_file)
{
	FILE *fp;
	
	fp = fopen(monty_file, "r");
	if (fp == NULL)
	{
		printf("Open Error\n");
		exit (EXIT_FAILURE);
	}
	read_and_tokenize(fp);
}
/**
* read_and_tokenize - Reads line from a file and tokinizes the content
* @fp: FILE struct pointer to the open file
*/
void read_and_tokenize(FILE *fp)
{
	char *buffer, *delim;
	char *token_1, *token_2;
	size_t n;
	unsigned int line_num = 0;

	delim = " \t\n";
	token_1 = token_2 = buffer = NULL;
	while (getline(&buffer, &n, fp) != -1)
	{
		token_1 = strtok(buffer, delim);
		if (token_1 == NULL)
		{
			fclose(fp);
			free(buffer);
			printf("Error tokenizing\n");
			exit (EXIT_FAILURE);
		}
		token_2 = strtok(NULL, delim);
		line_num++;
		check_command(line_num, token_1, token_2);

	}
}
/**
* check_command - checks if the commands are valid stack commands
* @token_1: first command to check
* @token_2: second command or argument to check
*/
void check_command(unsigned int line_num, char *token_1, char *token_2)
{
	int n, i;
	stack_t *stack = NULL;
	extern stack_t *head;
	instruction_t no_arg_func[] = {
			{ "pall", pall},
			{ NULL, NULL}
			};
	instruction_t arg_func[] = {
			{ "push", push},
			{NULL, NULL}
			};
	for (i = 0; no_arg_func[i].opcode != NULL; i++)
	{
		if (strcmp(token_1, no_arg_func[i].opcode) != 0)
			no_arg_func[i].f(&head, line_num);
	}
	for (i = 0; arg_func[i].opcode != NULL; i++)
	{
		if (strcmp(token_1, no_arg_func[i].opcode) != 0)
		{
			if(token_2 != NULL && isdigit(*token_2) != 0)
			{
				n = atoi(token_2);
				stack = create_stack(n);
				arg_func[i].f(&stack, line_num);
			}
			else
			{
				printf("Error: Second arg not int\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{

			printf("Error: Second arg not int\n");
			exit(EXIT_FAILURE);
		}
		
	}
}
/**
* create_stack - creates a new stack and populates n data
* @n: data for n element of the new stack struct
* Return: Pointer to the stack
*/
stack_t *create_stack(int n)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		printf("Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
	stack->n = n;
	return (stack);
}
