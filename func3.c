#include "monty.h"

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
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_arr = malloc(sizeof(stack_t));
	if (stack_arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack_arr->n = (*neww)->n; /*Assuming *neww contains the integer value*/
	stack_arr->prev = NULL;
	stack_arr->next = head;

	if (head != NULL)
	{
		head->prev = stack_arr;
	}
	head = stack_arr;
}

/**
 *f_pall - adds new node to stack
 *@neww: pointer to head stack
 *@line_number: value of element
 *Return: void
 */
void f_pall(stack_t **neww, unsigned int line_number)
{
	stack_t *stack_arr;

	(void)line_number;
	if (head == NULL)
		exit(EXIT_FAILURE);
	stack_arr = *neww;
	while (stack_arr != NULL)
	{
		printf("%d\n", stack_arr->n);
		stack_arr = stack_arr->next;
	}
}
