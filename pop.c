#include "monty.h"

/**
 *pop - removes an item from a list
 *@head: a doubly linked list
 *@line_number: line where function was called
 */

void pop(stack_t **head, int line_number)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	free(tmp);
}
