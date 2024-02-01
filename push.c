#include "monty.h"

/**
 *push_to_stack - adds a new element to the top of the stack
 *@head: a doubly linked list
 *@line_number: line number where funcation was called
 *@argument: a value to store in a list
 */

void push_to_stack(stack_t **head, int line_number, char *argument)
{
	stack_t *newnode = NULL;
	char *checked_argument;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	checked_argument = is_arg_integer(line_number, argument);

	if (checked_argument == NULL)
	{
		fprintf(stderr, "Error: Invalid argument at line %d\n", line_number);
		free(newnode);
		exit(EXIT_FAILURE);
	}
	newnode->n = atoi(checked_argument);
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		(*head)->prev = newnode;
		*head = newnode;
	}
}

/**
 *is_arg_integer - Checks if an argument is a valid integer.
 *@line_number: The line number of the Monty bytecode file.
 *@argument: The argument to be checked.
 *
 *Return: argument is returned if valid, else prints error message.
 */

char *is_arg_integer(int line_number, char *argument)
{
	int i;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; argument[i] != '\0'; i++)
	{
		if (i == 0 && (argument[i] == '-' || argument[i] == '+'))
		{
			continue;
		}

		if (!isdigit(argument[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (argument);
}

/**
 *display_stack - shows the first element in a stack
 *@head: a doubly linked list
 */

void display_stack(stack_t **head)
{
	stack_t *temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
