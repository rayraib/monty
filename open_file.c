#include "monty.h" 
/**
* open_file - opens a file to read
* @monty_file: file to open
*/
void open_file(char *monty_file)
{
	FILE *fp;
	
	fp = fopen(monty_file, "r");/*open file to read*/
	if (fp == NULL)
	{
		printf("Open Error\n");
		exit (EXIT_FAILURE);
	}
	read_and_tokenize(fp);/*call function to read to buffer and tokenize*/
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
	while (getline(&buffer, &n, fp) != -1)/*as long as there is next line */
	{
		token_1 = strtok(buffer, delim);/*tokenize first string*/
		if (token_1 == NULL)/*if failure to tokenize*/
		{
			fclose(fp);
			free(buffer);
			printf("Error tokenizing\n");
			exit (EXIT_FAILURE);
		}
		token_2 = strtok(NULL, delim);/*tokenize second string*/
		line_num++;
		check_command(line_num, token_1, token_2);/*call 
							command to check if strings are valid commands*/

	}
}
/**
* check_command - checks if the commands are valid stack commands
* @token_1: first command to check
* @token_2: second command or argument to check
*/
void check_command(unsigned int line_num, char *token_1, char *token_2)
{
	int check_ret;
	
	check_ret = check_no_arg_func(line_num, token_1);
	if (check_ret == -1)
	{
		check_arg_func(line_num, token_1, token_2);
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
