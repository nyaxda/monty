#include "monty.h"

/**
 * o_push - Pushes an integer onto the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the instruction.
 * Return: void
 */
void o_push(stack_t **head, unsigned int counter)
{
	int i, j = 0;
	bool flag = true;
	if (var.arg)
	{
		if (var.arg[0] == '-')
			j++;
		for (; var.arg[j]; j++)
		{
			if (var.arg[j] < '0' || var.arg[j] > '9')
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(var.file);
			free(var.data);
			stack_free(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(var.file);
		free(var.data);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(var.arg);
	if (var.storque == 0)
		add_dnodeint(head, i);
	else
		add_dnodeint_end(head, i);
}
