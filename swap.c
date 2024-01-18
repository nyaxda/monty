#include "monty.h"

/**
 * o_swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @counter: line counter
 * Return: void
 */
void o_swap(stack_t **stack, unsigned int counter)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
