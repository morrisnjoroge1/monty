#include "monty.h"

/**
* mod - computes the rest of the division of the second
* top element of the stack by the top element of the stack
* @head: pointer to the first node of the stack
* @counter: line number
*Description: top element of stack should contain the results
*stack is one element shorter
* Return: void
*/
void mod(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
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
num = h->next->n % h->n;
h->next->n = num;
*head = h->next;
free(h);
}
