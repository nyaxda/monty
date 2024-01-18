#include "monty.h"

/**
 * o_queue - data set to queue mode (FIFO)
 *
 * @stack: pointer to the stack
 * @counter: opcode line number
 */
void o_queue(stack_t **stack, unsigned int counter)
{
	(void)stack;
	(void)counter;
	var.storque = 1;
}
