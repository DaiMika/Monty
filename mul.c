#include "monty.h"
/**
 *mul - product of two numbers
 *@head: a doubly linked list (stack)
 *@line_number: line where function was called
 */

void mul(stack_t **head, int line_number)
{
	stack_t *tmp = NULL;
	int second_top_element, top_element = 0;

	tmp = *head;
	while (tmp != NULL)
	{
		top_element++;
		tmp = tmp->next;
	}

	if (top_element < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second_top_element = tmp->next->n * tmp->n;
	tmp->next->n = second_top_element;
	*head = tmp->next;

	free(tmp);
}
