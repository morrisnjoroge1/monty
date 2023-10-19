#include "monty.h"

/**
 * f_add - function that adds the top two elements of the stack.
 * @head:  head stack
 * @counter: number elements
 * Return: nothing
*/

void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int l = 0, x;

	h = *head;
	while (h)
	{
		h = h->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	x = h->n + h->next->n;
	h->next->n = x;
	*head = h->next;
	free(h);
}
