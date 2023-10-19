#include "monty.h"

/**
 *print_err - prints error message based on error occured
 *@error_num: error codes
 *
 *
 *
 */
void print_err(int error_num, ...)
{
	va_list vom;
	char *pos;
	int len = 0;

	va_start(vom, error_num);
	switch (error_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(vom, char *));
			break;
		case 3:
			len = va_arg(vom, int);
			pos = va_arg(vom, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", len, pos);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(vom, int));
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);/*SAME AS 1*/
}
/**
 *print_err1 - prints error message based on error
 *@error_num: represents the error code
 *
 */
void print_err1(int error_num, ...)
{
	va_list vom;
	char *pos;
	int len = 0;

	va_start(vom, error_num);
	switch (error_num)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(vom, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(vom, int));
			break;
		case 8:
			len = va_arg(vom, unsigned int);
			pos = va_arg(vom, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", len, pos);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(vom, unsigned int));
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 *print_err2 - prints error message based on error
 *@error_num: error code
 *
 */
void print_err2(int error_num, ...)
{
	va_list vom;
	int len = 0;

	va_start(vom, error_num);
	len = va_arg(vom, int);
	switch (error_num)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", len);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", len);
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}
