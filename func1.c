#include "monty.h"

/**
 *f_mul - multiplies the second top element of the stack with the
 *top element of the stack.
 *@head: pointer to head stack
 *@line_number: value of elememnts
 *Return: void
 */
void f_mul(stack_t **neww, unsigned int line_number)
{
	int num;

	if (neww == NULL || (*neww) == NULL || (*neww)->next == NULL)
		print_err1(8, line_number, "mul");

	(*neww) = (*neww)->next;
	num = (*neww)->n * (*neww)->prev->n;
	(*neww)->n = num;
	free((*neww)->prev);
	(*neww)->prev = NULL;
}

/**
 *f_swap - swaps the top two elements of the stack.
 *@head: pointer to head stack
 *@line_number: value of element
 *Description: usage: swap
 *Return: void
 */
void f_swap(stack_t **neww, unsigned int line_number)
{
	stack_t *temp;

	if (neww == NULL || (neww) == NULL || (*neww)->next == NULL)
		print_err1(8, line_number, "swap");

	temp = (*neww)->next;
	(*neww)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *neww;
	temp->next = *neww;
	(*neww)->prev = temp;
	temp->prev = NULL;
	*neww = temp;
}


/**
 *f_pint -  prints the value at the top of the stack, followed by a new line.
 *@head: pointer to head stack
 *@line_number: value element
 *Return: void
 */
void f_pint(stack_t **neww, unsigned int line_number)
{
	if (neww == NULL || *neww == NULL)
		print_err1(6, line_number);
	printf("%d\n", (*neww)->n);
}

/**
 *f_pop -  removes the top element of the stack.
 *@head: pointer to head stack
 *@line_number: element value
 *Return: void
 */
void f_pop(stack_t **neww, unsigned int line_number)
{
	stack_t *stack_arr;

	if (neww == NULL || *neww == NULL)
		print_err1(7, line_number);
	stack_arr = *neww;
	*neww = stack_arr->next;

	if (*neww != NULL)
	{
		(*neww)->prev = NULL;
	}
	free(stack_arr);
}
