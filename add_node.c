#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to the head of the stack
 * @n: integer to be added
 * Return: the address of the new element, or NULL if it failed
 */
void add_dnodeint(stack_t **head, int n)
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
	if (temp != NULL)
		temp->prev = new_node;
	new_node->next = temp;
	new_node->prev = NULL;
	*head = new_node;
}
