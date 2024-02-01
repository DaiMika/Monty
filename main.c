#include "monty.h"

/**
 *main - entry point
 *@argc: argument count
 *@argv: argument vector
 *
 *Return: Always 1
 */

int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (1);
	}

	process_file(argv[1], &head);

	return (0);
}
