#include "monty.h"

/**
 *is_valid_instruction - checks if an instrucion is valid
 *@instruction: instruction
 *
 *Return: an integer
 */

int is_valid_instruction(const char *instruction)
{
	unsigned int i;
	const char *opcode[] = {
		"push",
		"pall",
		"pint",
		"pop",
		"swap",
		"add",
		"nop",
		"sub",
		"div",
		"mul",
		"mod",
		"pchar",
		"pstr",
		"rotl",
		"rotr"
	};

	for (i = 0; i < sizeof(opcode) / sizeof(opcode[0]); i++)
	{
		if (strcmp(instruction, opcode[i]) == 0)
		{
			return (1);
		}
	}

	return (0);
}

/**
 *process_file - execute instructions in a file
 *@filen: an file to read
 *@head: a doulbly linked list
 */

void process_file(char *filen, stack_t **head)
{
	char line[MAX_LEN];
	unsigned int line_number = 0;
	char *opcode = NULL, *argument = NULL;
	instruction_t instruction;
	FILE *file;

	file = fopen(filen, "r");
	if (file == NULL)
	{
		perror("Error: Can't open file");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		line_number++;

		opcode = strtok(line, " \t\n$");
		if (strcmp(opcode, "push") == 0)
		{
			argument = strtok(NULL, " \t$\n");
		}

		if (!is_valid_instruction(opcode))
		{
			fprintf(stderr, "Error: Invalid opcode at line %u\n", line_number);
			fclose(file);
			freeList(*head);
			exit(EXIT_FAILURE);
		}

		instruction.opcode = opcode;
		_execute(instruction.opcode, head, line_number, argument);
	}
	fclose(file);
	freeList(*head);
}

/**
 *_execute - executes an instruction
 *@opcode: instruction code
 *@head: a doubly linked list
 *@line_number: line where function was called
 *@argument: argument passed to instruction
 */

void _execute(char *opcode, stack_t **head, int line_number, char *argument)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(head, line_number, argument);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(head);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(head, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(head, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(head, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(head, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(head, line_number);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(head, line_number);
	}
	else if (strcmp(opcode, "div") == 0)
	{
		division(head, line_number);
	}
	else if (strcmp(opcode, "mul") == 0)
	{
		mul(head, line_number);
	}
	else if (strcmp(opcode, "mod") == 0)
	{
		mod(head, line_number);
	}

}
