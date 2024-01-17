#include "monty.h"

/**
 * o_pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the top of the stack
 * @counter: line counter
 * Return: void
 */
void o_pall(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
