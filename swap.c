#include "monty.h"

/**
 *swap -swaps two values
 *@head: a doubly linked list
 *@line_number: line in wich call function is called
 */

void swap(stack_t **head, int line_number)
{
	stack_t *tmp;
	int len = 0, num;

	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	num = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = num;
}
