#include "monty.h"

/**
 * o_rotl - rotates the stack to the top
 *
 * @stack: pointer to the stack
 * @counter: opcode line number
 */
void o_rotl(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack;
	int temp_n;

	(void)counter;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp_n = temp->n;
	while (temp->next != NULL)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	tempt->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
