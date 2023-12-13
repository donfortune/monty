#include "monty.h"
/**
 *  main - Main
 *
 *  @argc: Number of args
 *
 *  @argv: Command line args
 *
 *  Return: Void
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	process_file(file);

	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * process_file - processes each operation line by line in the monty file
 * @file: file to process
 *
 * Return: Void
 */

void process_file(FILE *file)
{
	stack_t *head = NULL;
	char str[1024], *temp, *operator_array[2];
	size_t line_count = 0;
	int is_stack = 1;
	void (*operator_function)(stack_t **stack, size_t line_number);

	while (fgets(str, sizeof(str), file) != NULL)
	{
		line_count++;

		operator_array[0] = strtok(str, "\n ");

		if (operator_array[0] == NULL)
			get_nop(&head, line_count);
		else if (strcmp("queue", operator_array[0]) == 0)
			is_stack = 0;
		else if (strcmp("stack", operator_array[0]) == 0)
			is_stack = 1;
		else if (strcmp("push", operator_array[0]) == 0)
		{
			temp = strtok(NULL, "\n ");

			get_push(&head, line_count, temp, is_stack);
		}
		else if (operator_array[0][0] != '#')
		{
			operator_function = go(operator_array[0], line_count, &head);
			if (operator_function == NULL && line_count == 0)
			{
				fprintf(stderr, "L%lu: unknown instruction %s\n",
						line_count, operator_array[0]);
				exit(EXIT_FAILURE);
			}
			operator_function(&head, line_count);
		}
	}
	if (head)
		get_free(head);
}
