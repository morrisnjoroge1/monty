#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: pointer to the head of the stack
*/
void free_stack(stack_t *head)
{
stack_t *stack_arr;

stack_arr = head;
while (head)
{
stack_arr = head->next;
free(head);
head = stack_arr;
}
}

