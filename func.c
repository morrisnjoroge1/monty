#include "monty.h"

/**
 *f_add - adds the top two elements of the stack.
 *@neww: pointer to head stack
 *@line_number: value of new node
 *Return: void
 */
void f_add(stack_t **neww, unsigned int line_number)
{
	int sum;

	if (neww == NULL || *neww == NULL || (*neww)->next == NULL)
		print_err1(8, line_number, "add");

	(*neww) = (*neww)->next;
	sum = (*neww)->n + (*neww)->prev->n;
	(*neww)->n = sum;
	free((*neww)->prev);
	(*neww)->prev = NULL;
}

/**
 *f_div -  divides the second top element of the stack by the
 *top element of the stack.
 *@neww: pointer to head stack
 *@line_number: value of new node
 *Return: void
 */
void f_div(stack_t **neww, unsigned int line_number)
{
	int sum;

	if (neww == NULL || *neww == NULL || (*neww)->next == NULL)
		print_err1(8, line_number, "div");

	if ((*neww)->n == 0)
		print_err1(9, line_number);
	(*neww) = (*neww)->next;
	sum = (*neww)->n / (*neww)->prev->n;
	(*neww)->n = sum;
	free((*neww)->prev);
	(*neww)->prev = NULL;
}

/**
 *f_sub -  subtracts the top element of the stack from
 *the second top element of the stack.
 *@neww: pointer to head stack
 *@line_number: value of node
 *Return: void
 */
void f_sub(stack_t **neww, unsigned int line_number)
{
	int num;

	if (neww == NULL || *neww == NULL || (*neww)->next == NULL)
		print_err1(8, line_number, "sub");

	(*neww) = (*neww)->next;
	num = (*neww)->n - (*neww)->prev->n;
	(*neww)->n = num;
	free((*neww)->prev);
	(*neww)->prev = NULL;
}

/**
 *f_nop - doesn’t do anything.
 *@neww: pointer to head stack
 *@line_number: value of element
 *Return: void
 */
void f_nop(stack_t **neww, unsigned int line_number)
{
	(void)neww;
	(void)line_number;
}

/**
 *f_mod - computes the rest of the division of the second top element of
 *the stack by the top element of the stack.
 *@neww: doublepointer to head stack
 *@line_number: value element
 */
void f_mod(stack_t **neww, unsigned int line_number)
{
	int num;

	if (neww == NULL || *neww == NULL || (*neww)->next == NULL)
		print_err1(8, line_number, "mod");

	if ((*neww) == 0)
		print_err1(9, line_number);
	num = (*neww)->n % (*neww)->prev->n;
	(*neww)->n = num;
	free((*neww)->prev);
	(*neww)->prev = NULL;
}
