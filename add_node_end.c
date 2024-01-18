#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list
 * @head: pointer to the head of the stack
 * @n: integer to be added
 * Return: void
 */
void add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(0);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;  // Initialize new_node->prev to NULL
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	else
	{
		*head = new_node;
	}
}
