#include "monty.h"

/**
 * o_pchar - prints the ASCII value of topmost stack integer
 *
 * @stack: pointer to the stack
 * @counter: opcode line number
 */
void o_pchar(stack_t **stack, unsigned int counter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		free(var.data);
		fclose(var.file);
		stack_free(*stack);
		exit(EXIT_FAILURE);	
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		free(var.data);
		fclose(var.file);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
