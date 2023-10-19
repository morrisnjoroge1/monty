#include "monty.h"

/**
 *f_mul - multiplies the second top element of the stack with the
 *top element of the stack.
 *@head: double pointer to the head stack
 *@line_number: value of elememnts
 *Return: void
 */
void f_mul(stack_t **head, unsigned int line_number)
{
	int num;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		print_err1(8, line_number, "mul");

	(*head) = (*head)->next;
	num = (*head)->n * (*head)->prev->n;
	(*head)->n = num;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *f_swap - swaps the top two elements of the stack.
 *@head: double pointer to the head stack
 *@line_number: value of element
 *Description: usage: swap
 *Return: void
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		print_err1(8, line_number, "swap");

	temp = (*head)->next;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *head;
	temp->next = *head;
	(*head)->prev = temp;
	temp->prev = NULL;
	*head = temp;
}


/**
 *f_pint -  prints the value at the top of the stack, followed by a new line.
 *@head: pointer to head of stack
 *@line_number: value element
 *Return: void
 */
void f_pint(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
		print_err1(6, line_number);
	printf("%d\n", (*head)->n);
}

/**
 *f_pop -  removes the top element of the stack.
 *@head: pointer to head stack
 *@line_number: element value
 *Return: void
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *stack_arr;

	if (head == NULL || *head == NULL)
		print_err1(7, line_number);
	stack_arr = *head;
	*head = stack_arr->next;

	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(stack_arr);
}
