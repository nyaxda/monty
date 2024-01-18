#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct variables - variables used in the program
 * @arg: argument
 * @file: file pointer
 * @data: data
 * @storque: stack or queue
 */

typedef struct variables
{
	char *arg;
	FILE *file;
	char *data;
	unsigned int storque;
} vars;
extern vars var;

int execute(stack_t **stack, unsigned int counter, FILE *file, char *cont);
void o_push(stack_t **head, unsigned int counter);
void stack_free(stack_t *stack);
void add_dnodeint(stack_t **head, int n);
void add_dnodeint_end(stack_t **head, int n);
void o_pall(stack_t **stack, __attribute__((unused)) unsigned int counter);
void o_pint(stack_t **stack, unsigned int counter);
void o_pop(stack_t **stack, unsigned int counter);
void o_swap(stack_t **stack, unsigned int counter);
void o_add(stack_t **stack, unsigned int counter);
void o_nop(stack_t **stack, unsigned int counter);
void o_sub(stack_t **stack, unsigned int counter);
void o_div(stack_t **stack, unsigned int counter);
void o_mul(stack_t **stack, unsigned int counter);
void o_pchar(stack_t **stack, unsigned int counter);
void o_mod(stack_t **stack, unsigned int counter);
void o_pstr(stack_t **stack, unsigned int counter);
void o_rotl(stack_t **stack, unsigned int counter);
void o_rotr(stack_t **stack, unsigned int counter);
void o_queue(stack_t **stack, unsigned int counter);
void o_stack(stack_t **stack, unsigned int counter);
#endif /*MONTY_H*/
