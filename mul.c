#include "monty.h"

/**
* mul - multiplies the top two elements of the stack.
* @head: pointer to the first head node in stack
* @counter: line number
* Return: void
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, num;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	num = h->next->n * h->n;
	h->next->n = num;
	*head = h->next;
	free(h);
}
