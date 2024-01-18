#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a tail stack_t list
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
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	if (temp == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		new_node->prev = temp;
		temp->next = new_node;
	}
}
