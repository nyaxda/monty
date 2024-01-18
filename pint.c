#include "monty.h"

/**
 * o_pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the top of the stack
 * @counter: line counter
 * Return: void
*/
void o_pint(stack_t **stack, unsigned int counter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
