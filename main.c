#include "monty.h"
int main(int argc, char **argv)
{
	extern stack_t *head;
	(void) head;
	
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	return (0);
}
