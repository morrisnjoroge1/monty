#include "monty.h"

/**
 * f_div - function that divides the top two elements of the stack.
 * @head: head stack
 * @counter: line_number
 * Return: nothing
*/
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = h->next->n / h->n;
	h->next->n = num;
	*head = h->next;
	free(h);
}
