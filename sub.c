#include "monty.h"

/**
 * o_sub - subtracts top two elements in stack
 *
 * Description: it will store the difference in the
 *              2nd element of the stack
 *
 * @stack: pointer to stack
 * @counter: opcode line number
 */
void o_sub(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack;
	size_t len = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n - temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
