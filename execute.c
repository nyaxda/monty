#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: pointer to the top of the stack
 * @counter: line counter
 * @file: file pointer
 * @cont: line content
 * Return: void
 */
int execute(stack_t **stack, unsigned int counter, FILE *file, char *cont)
{
	unsigned int i = 0;
	char *token;
	instruction_t options[] = {
		{"push", o_push}, {"pall", o_pall}, {"pint", o_pint},
		{"pop", o_pop}, {"swap", o_swap}, {"add", o_add},
		{"nop", o_nop}, {"sub", o_sub}, {"div", o_div},
		{"mul", o_mul}, {"mod", o_mod}, {"pchar", o_pchar},
		{"pstr", o_pstr}, {"rotl", o_rotl}, {"rotr", o_rotr},
		{"queue", o_queue}, {"stack", o_stack}, {NULL, NULL}
	};
	token = strtok(cont, " \n\t");
	if (token == NULL)
		return (0);
	if (token && token[0] == '#')
		return (0);
	var.arg = strtok(NULL, " \n\t");
	while (options[i].opcode != NULL && token)
	{
		if (strcmp(token, options[i].opcode) == 0)
		{
			options[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (options[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, token);
		free(cont);
		fclose(file);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
