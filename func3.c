#include "monty.h"

/**
 *add_queue - add node to queue
 *@neww: new node
 *@line_number: unsed parameter
 *Return: void
 */
void add_queue(stack_t **neww, __attribute__((unused))unsigned int line_number)
{
	stack_t *stack_arr;

	if (neww == NULL || *neww == NULL)
		exit(EXIT_FAILURE);/*SAME AS EXIT(1);*/
	if (head == NULL)
	{
		head = *neww;
		return;
	}
	stack_arr = head;

	while (stack_arr->next != NULL)
		stack_arr = stack_arr->next;
	stack_arr->next = *neww;
	(*neww)->prev = stack_arr;
}

/**
 *f_push - adds node to stack
 *@neww: new node
 *@line_number: unsesd parameter
 *Return: void
 */
void f_push(stack_t **neww, __attribute__((unused))unsigned int line_number)
{
	stack_t *stack_arr;

	if (neww == NULL || *neww == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *neww;
		return;
	}
	stack_arr = head;
	head = *neww;
	head->next = stack_arr;
	stack_arr->prev = head;
}

/**
 *f_pall - adds new node to stack
 *@head: pointer to head stack
 *@line_number: value of element
 *Return: void
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *stack_arr;

	(void)line_number;
	if (head == NULL)
		exit(EXIT_FAILURE);
	stack_arr = *head;
	while (stack_arr != NULL)
	{
		printf("%d\n", stack_arr->n);
		stack_arr = stack_arr->next;
	}
}
