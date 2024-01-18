#include "monty.h"

/**
 * o_rotl - rotates the stack to the top
 *
 * @stack: pointer to the stack
 * @counter: opcode line number
 */
void o_rotl(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack, *h;

	(void)counter;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	h = temp->next;
	h->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
