#include "monty.h"

/**
* pstr - prints the string starting at the top of the stack,
* followed by a new
* @head: pointer to the first head node of stack
* @counter: line number
* Return: void
*/
void pstr(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
