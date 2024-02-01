#include "monty.h"

/**
 *sub - subtract two values in a list
 *@head: a doulbly linked list
 *@line_number: line where function was called
 */
void sub(stack_t **head, int line_number)
{
	stack_t *tmp;
	int top_element = 0, second_top_element;

	tmp = *head;

	while (tmp != NULL)
	{
		top_element++;
		tmp = tmp->next;
	}

	if (top_element < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	second_top_element = tmp->next->n - tmp->n;
	tmp->next->n = second_top_element;
	*head = tmp->next;
	free(tmp);
}
