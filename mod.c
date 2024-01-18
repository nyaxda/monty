#include "monty.h"

/**
 * o_mod - takes modulus of top two elements in stack
 *
 * Description: it will store the mod in the
 *              2nd element of the stack and free the 1st node.
 *
 * @stack: pointer to stack
 * @counter: opcode line number
 */
void o_mod(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack;
	size_t len = 0;
	int result;

	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n % temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
