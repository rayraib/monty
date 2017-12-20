#include "monty.h"
/**
* free_stack - frees each element of the stack
*/
void free_stack(void)
{
	if (head != NULL)
		while (head->next != NULL)
		{
			head = head->next;
			free(head->prev);
		}
		free(head);
}
