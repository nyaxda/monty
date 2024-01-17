#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
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
        fprintf(stderr, "Error: malloc failed\n");
        fclose(var.file);
        free(var.data);
        stack_free(*head);
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    if (temp != NULL)
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        *head = new_node;
    }
}
