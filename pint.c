#include "monty.h"

/**
 *pint -  prints the value at the top of the stack
 *@head: a doubly linked list
 *@line_number: the line where function is called
 */

void pint(stack_t **head, int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*head)->n);
	}
}
