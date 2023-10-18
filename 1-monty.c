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

/**
* mul - multiplies the top two elements of the stack.
* @head: pointer to the first head node in stack
* @counter: line number
* Return: void
*/
void  mul(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, stack_arr;

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
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
stack_arr = h->next->n * h->n;
h->next->n = aux;
*head = h->next;
free(h);
}

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
int len = 0, stack_arr;

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
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
stack_arr = h->next->n % h->n;
h->next->n = stack_arr
*head = h->next;
free(h);
}

* pchar - prints the char at the top of the stack,
* followed by a new line
* @head: pointer to the first head node of stack
* @counter: line number
* Return: void
*/
void pchar(stack_t **head, unsigned int counter)
{
stack_t *h;

h = *head;
if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
if (h->n > 127 || h->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", h->n);
}

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

