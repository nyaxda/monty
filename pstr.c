#include "monty.h"

/**
 * o_pstr - prints the string starting at the top of the stack
 *
 * @stack: pointer to the stack
 * @counter: opcode line number
 */
void o_pstr(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack;

	(void)counter;
	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n < 128))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
