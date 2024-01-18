#include "monty.h"

/**
 * o_rotr - rotates the stack to the bottom
 *
 * @stack: pointer to the stack
 * @counter: opcode line number
 */
void o_rotr(stack_t **stack, unsigned int counter)
{
	stack_t *h = *stack, *temp;

	(void)counter;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (h->next != NULL)
		h = h->next;
	temp = h->prev;
	temp->next = NULL;
	h->prev = NULL;
	h->next = *stack;
	(*stack)->prev = h;
	(*stack) = h;
}
