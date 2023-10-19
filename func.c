#include "monty.h"

/**
 *f_add - adds the top two elements of the stack.
 *@head: pointer to head stack
 *@line_number: value of new node
 *Return: void
 */
void f_add(stack_t **head, unsigned int line_number)
{
	int sum;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		print_err1(8, line_number, "add");

	(*head) = (*head)->next;
	sum = (*head)->n + (*head)->prev->n;
	(*head)->n = sum;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *f_div -  divides the second top element of the stack by the
 *top element of the stack.
 *@head: pointer to top head stack
 *@line_number: value of new node
 *Return: void
 */
void f_div(stack_t **head, unsigned int line_number)
{
	int sum;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		print_err1(8, line_number, "div");

	if ((*head)->n == 0)
		print_err1(9, line_number);
	(*head) = (*head)->next;
	sum = (*head)->n / (*head)->prev->n;
	(*head)->n = sum;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *f_sub -  subtracts the top element of the stack from
 *the second top element of the stack.
 *@head: pointer to thehead of node
 *@line_number: value of node
 *Return: void
 */
void f_sub(stack_t **head, unsigned int line_number)
{
	int num;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		print_err1(8, line_number, "sub");

	(*head) = (*head)->next;
	num = (*head)->n - (*head)->prev->n;
	(*head)->n = num;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *f_nop - doesn’t do anything.
 *@head: double pointer to the head of stack
 *@line_number: value of element
 *Return: void
 */
void f_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 *f_mod - computes the rest of the division of the second top element of
 *the stack by the top element of the stack.
 *@head: doublepointer to head stack
 *@line_number: value element
 */
void f_mod(stack_t **head, unsigned int line_number)
{
	int num;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		print_err1(8, line_number, "mod");

	if ((*head) == 0)
		print_err1(9, line_number);
	num = (*head)->n % (*head)->prev->n;
	(*head)->n = num;
	free((*head)->prev);
	(*head)->prev = NULL;
}
