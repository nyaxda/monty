#include "monty.h"

/**
 * o_rotl - rotates the stack to the top
 *
 * @stack: pointer to the stack
 * @counter: opcode line number
 */
void o_rotl(stack_t **stack, unsigned int counter)
{
	stack_t *h = *stack, *temp;

	(void)counter;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = (*stack)->next;
	temp->prev = NULL;

	while (h->next != NULL)
		h = h->next;

	h->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = h;
	(*stack) = temp;
}
