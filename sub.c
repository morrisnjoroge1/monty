#include "monty.h"

/**
*f_sub- sustration of top element from second element
*@head: stack head
*@counter: line_number
*Return: no return
*/
void f_sub(stack_t **head, unsigned int counter)
{
stack_t *aux;
int num, nodes;

aux = *head;
for (nodes = 0; aux != NULL; nodes++)
aux = aux->next;
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.command);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = *head;
num = aux->next->n - aux->n;
aux->next->n = num;
*head = aux->next;
free(aux);
}
