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
    instruction_t options[] = 
    {
        {"push", o_push},
        {"pall", o_pall}
    };
    token = strtok(cont, " \n\t");
    if (token == NULL)
        return (0);
    if (token[0] == '#')
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
