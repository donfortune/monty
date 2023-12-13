#include "monty.h"
/**
 * get_pchar - function that prints the char at the top of the stack
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 11. pchar
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_pchar(stack_t **stack, size_t line_number)
{
	if ((stack == NULL) || ((*stack) == NULL))
	{
		fprintf(stderr, "L%lu: can't pchar, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (!(is_ascii((*stack)->n)))
	{
		fprintf(stderr, "L%lu: can't pchar, value out of range\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * is_ascii - confirms whether a value is an ascii char
 * @c: the char to check
 *
 * Return: 0 or a true value
 */
int is_ascii(int c)
{
	return (!(c & ~0x7F));
}
