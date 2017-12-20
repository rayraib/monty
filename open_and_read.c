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
		fclose(fp);
		printf("Error: Can't open file\n");
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
			continue;
		token_2 = strtok(NULL, delim);/*tokenize second string*/
		line_num++;
		if(check_no_arg_func(line_num, token_1) == -1)
		{
			check_arg_func(line_num, token_1, token_2, buffer, fp);
		}
	}
	free (buffer);
	fclose(fp);
}
/**
* create_stack - creates a new stack and populates n data
* @n: data for n element of the new stack struct
* @buf: Pointer to the string of commands from monty bytecode file
* @fp: pointer to the open monty bytecode file
* Return: Pointer to the stack
*/
stack_t *create_stack(int n, char *buf, FILE *fp)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		free (buf);	
		fclose (fp);
		printf("Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
	stack->n = n;
	return (stack);
}
