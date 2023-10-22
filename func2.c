#include "monty.h"

/**
 *f_pchar - prints the char at the top of the stack, followed by a new line.
 *@neww: pointer to head stack
 *@line_number: interger represents element value
 *Description: usage: pchar
 *If the value is not in the ascii table (man ascii) print the error
 *Return: void
 */
void f_pchar(stack_t **neww, unsigned int line_number)
{
	int table;

	if (neww == NULL || (*neww) == NULL)
		print_err2(11, line_number);
	table = (*neww)->n;
	if (table < 0 || table > 127)
		print_err2(10, line_number);
	printf("%c\n", table);
}

/**
 *f_pstr -  prints the string starting at the top of the stack.
 *@neww: pointer to  head stack
 *@line_number: value of the element
 *Return: void
 */
void f_pstr(stack_t **neww, __attribute__((unused))unsigned int line_number)
{
	int table;
	stack_t *temp;

	if (neww == NULL || (*neww) == NULL)
	{
		printf("\n");
		return;
	}

	temp = *neww;
	while (temp != NULL)
	{
		table = temp->n;
		if (table < 0 || table > 127)
			break;
		printf("%c", table);
		temp = temp->next;
	}
	printf("\n");
}

/**
 *rotl - rotates the stack to the top.
 *@neww: pointer to head stack
 *@line_number: element value
 *Description: usage: rotl
 *The top element of the stack becomes the last one, and the second top
 *element of the stack becomes the first one
 *rotl never fails
 *Return: void
 */
void rotl(stack_t **neww, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (neww == NULL || (*neww) == NULL || (*neww)->next == NULL)
		return;
	temp = *neww;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *neww;
	(*neww)->prev = temp;
	*neww = (*neww)->next;
	(*neww)->prev->next = NULL;
	(*neww)->prev = NULL;
}


/**
 *rotr -  rotates the stack to the bottom.
 *@neww: pointer to  head stack
 *@line_number: unused integer represents value of element
 *Descriptiojn: usage: rotr
 *The last element of the stack becomes the top element of the stack
 *rotr never fails
 *Return: void
 */
void rotr(stack_t **neww, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (neww == NULL || (*neww) == NULL || (*neww)->next == NULL)
		return;

	temp = *neww;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *neww;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*neww)->prev = temp;
	(*neww) = temp;
}

