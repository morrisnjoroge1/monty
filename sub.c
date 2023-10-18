include "monty.h"
/**
*sub- sustracts top élément from second element
*in the stack
*@head: pointer to the head stack
*@counter: line numbers
*Return: void
*/
void sub(stack_t **head, unsigned int counter)
{
stack_t *stack_arr
int num, a;

stack_arr = *head;
for (a = 0; stack_arr != NULL; a++)
stack_arr = stack_arr->next;
if (a < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(file);
free(content);
free_stack(*head);
exit(EXIT_FAILURE);
}
stack_arr = *head;
num = stack_arr->next->n - stack_arr->n;
stack_arr->next->n = num;
*head = stack_arr->next;
free(stack_arr);
}
