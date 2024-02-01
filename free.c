#include "monty.h"

/**
 *freeList - free  a node
 *@head: a pointer to a node
 */

void freeList(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
