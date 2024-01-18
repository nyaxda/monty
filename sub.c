#include "monty.h"

/**
 * o_sub - subtract the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @counter: line counter
 * Return: void
 */
void o_sub(stack_t **stack, unsigned int counter)
{
	stack_t *temp;
	int len = 0, result = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->n - temp->next->n;
	temp->next->n = result;
	*stack = (*stack)->next;
	free(temp);
}
