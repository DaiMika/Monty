#include "monty.h"

/**
 *add -add two number
 *@head: a doubly linked list
 *@line_number: line function call was made
 */

void add(stack_t **head, int line_number)
{
	stack_t *tmp;
	int len = 0, num;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	num = tmp->n + tmp->next->n;
	tmp->next->n = num;
	*head = tmp->next;
}
