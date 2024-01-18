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
	int len;
	int result;

	temp = *stack;
	for (len = 0; temp != NULL; len++)
		temp = temp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
