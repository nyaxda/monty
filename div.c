#include "monty.h"

/**
 * o_div - divides top two elements in stack
 *
 * Description: it will store the difference in the
 *              2nd element of the stack and delete the first.
 *              Divisor(2nd element) must not equal to 0
 *
 * @stack: pointer to stack
 * @counter: opcode line number
 */
void o_div(stack_t **stack, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (temp->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n / temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
