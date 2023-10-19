#include "monty.h"
stack_t *head = NULL;

/**
 *main - monty code interpreter.
 *@argc: number of arguments
 *@argv: array of arguments
 *Return: 0 on success 0r 1 otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_fl(argv[1]);
	free_stack();
	return (0);
}
/**
 *free_stack - frees doubly linked lidt in stack
 *Return: void
 */
void free_stack(void)
{
	stack_t *stack_arr;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		stack_arr = head;
		head = head->next;
		free(stack_arr);
	}
}

/**
 *create - creates a new node to linked list
 *@n: integer
 *Return: address of newnode or NULL otherwise
 */
stack_t *create(int n)
{
	stack_t *add;

	add = malloc(sizeof(stack_t));
	if (add == NULL)
		print_err(4);
	add->next = NULL;
	add->prev = NULL;
	add->n = n;
	return (add);
}

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
