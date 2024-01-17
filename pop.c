#include "monty.h"

/**
 * o_pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @counter: line counter
 * Return: void
 */
void o_pop(stack_t **stack, unsigned int counter)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
