#include "monty.h"

/**
 *add_node - add node to the head stack
 *@head: double pointer to the node at head stack
 *@n: value of new node
 *Return: void
 */
void add_node(stack **head, int n)
{
	stack_t *neww, *stack_arr;

	stack_arr = *head;
	neww = malloc(sizeof(stack_t));
	if (neww == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (stack_arr)
		stack_arr->prev = neww;
	neww->n = n;
	neww->next = *head;
	neww->prev = NULL;

	*head = neww;
}
