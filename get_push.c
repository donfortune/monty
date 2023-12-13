#include "monty.h"
/**
 * get_push - function that pushes an element onto top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * @temp: Pointer to instruction
 * @is_stack: value to determine node arrangement.
 * Description: 0. push, pall
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_push(stack_t **stack, size_t line_number, char *temp, int is_stack)
{

	stack_t *new_top, *list = *stack;


	if (temp == NULL || _isdigit(temp) == 0)
	{
		fprintf(stderr, "L%ld: usage: push integer\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_top->n = atoi(temp);
	new_top->next = NULL;
	new_top->prev = NULL;
	if (*stack && is_stack)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
		*stack = new_top;
	}
	else if (*stack && !is_stack)
	{
		new_top->next = NULL;
		while (list->next)
			list = list->next;
		new_top->prev = list;
		list->next = new_top;
		return;
	}
	*stack = new_top;
}


/**
 *  _isdigit - Finds if char is a digit or not
 *
 *  @str: Character passed in
 *
 *  Return: 1 for digit, 0 if not
 */

int _isdigit(char *str)
{

	int i = 0;


	if (str[i] == ' ' || str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}

	return (1);
}
