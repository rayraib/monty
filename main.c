#include "monty.h"
stack_t *head = NULL;
/**
* main - entry point
* @argc: Number of arguments received
* @argv: Pointer to an array of string of arguments
* Return: 0 if succes, 1 if failure
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	return (0);
}
