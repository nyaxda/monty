#include "monty.h"

/**
 * stack_free - frees the stack
 * @stack: pointer to the top of the stack
 * Return: void
 */
void stack_free(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
