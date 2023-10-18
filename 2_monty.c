#include "monty.h"
/**
*rotl- rotates the stack to the top
*@head: pointer to the first node of stack 
*@counter: line number
*Description: top element becomes last and second top becomes first
*Return: void
*/
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
stack_t *temp = *head, *stack_arr;

if (*head == NULL || (*head)->next == NULL)
{
return;
}
stack_arr= (*head)->next;
stack_arr->prev = NULL;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = *head;
(*head)->next = NULL;
(*head)->prev = temp;
(*head) = stack_arr;
}

/**
*rotr- rotates the stack to the bottom
*@head: pointer to the stack head
*@counter: line number
*Return: void
*/
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *set;

set = *head;
if (*head == NULL || (*head)->next == NULL)
return;
while (set->next)
{
set = set->next;
}
set->next = *head;
set->prev->next = NULL;
set->prev = NULL;
(*head)->prev = set;
(*head) = set;
}

/**
* stack - sets the format of data to stack
* @head: pointer to the stack head
* @counter: line number
* Return: void
*/
void stack(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifo = 0;
}



/**
* queue - sets format of data in queue
* @head: pointer to the stack head
* @counter: line_number
* Return: no return
*/
void queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifo = 1;
}

/**
* addnode_end - add node to the tail stack
* @n: value of new node
* @head: head of the stack
* Return: void
*/
void addnode_end(stack_t **head, int n)
{
stack_t *add, *stack_arr;

stack_arr = *head;
add = malloc(sizeof(stack_t));
if (add == NULL)
{
printf("Error\n");
}
add->n = n;
add->next = NULL;
if (stack_arr)
{
while (stack_arr->next)
stack_arrr = stack_arr->next;
}
if (!stuck_arr)
{
*head = add;
add->prev = NULL;
}
else
{
stack_arr->next = add;
add->prev = stack_arr;
}
}

