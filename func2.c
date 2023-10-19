#include "monty.h"

/**
 *f_pchar - prints the char at the top of the stack, followed by a new line.
 *@head: pointer to head stack
 *@line_number: interger represents element value
 *Description: usage: pchar
 *If the value is not in the ascii table (man ascii) print the error
 *Return: void
 */
void f_pchar(stack_t **head, unsigned int line_number)
{
	int table;

	if (head == NULL || (*head) == NULL)
		print_err2(11, line_number);
	table = (*head)->n;
	if (table < 0 || table > 127)
		print_err2(10, line_number);
	printf("%c\n", table);
}

/**
 *p_str -  prints the string starting at the top of the stack.
 *@head: pointer to the top head of stack
 *@line_number: value of the element
 *Return: void
 */
void p_str(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	int table;
	stack_t *temp;

	if (head == NULL || (*head) == NULL)
	{
		printf("\n");
		return;
	}

	temp = *head;
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
 *@head: pointer to the head stack
 *@line_number: element value
 *Description: usage: rotl
 *The top element of the stack becomes the last one, and the second top
 *element of the stack becomes the first one
 *rotl never fails
 *Return: void
 */
void rotl(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		return;
	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}


/**
 *rotr -  rotates the stack to the bottom.
 *@head: pointer to the head stack
 *@line_number: unused integer represents value of element
 *Descriptiojn: usage: rotr
 *The last element of the stack becomes the top element of the stack
 *rotr never fails
 *Return: void
 */
void rotr(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		return;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
