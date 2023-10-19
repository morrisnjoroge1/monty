#include "monty.h"

/**
 *open_fl - opens file
 *@sile_name: file name
 *Return: void
 */
void open_fl(char *sile_name)
{
	FILE *pd = fopen(sile_name, "r");

	if (sile_name == NULL || pd == NULL)
		print_err(2, sile_name);

	read_fl(pd);
	fclose(pd);
}

/**
 *read_fl - reads file
 *@pd: file
 *Return: void
 */
void read_fl(FILE *pd)
{
	int a, format = 0;
	char *buff = NULL;
	size_t len = 0;

	for (a = 1; getline(&buff, &len, pd) != -1; a++)
	{
		format = parse_line(buff, a, format);
	}
	free(buff);
}


/**
 *parse_line - parses
 *@buff: ponter to character buffer
 *@line_number: integer
 *@format: format
 *Return: 0 if in stack or 1 in in queue
 */
int parse_line(char *buff, int line_number, int format)
{
	char *val, *opcode;
	const char *delim = "\n";

	if (buff == NULL)
		print_err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	execute(opcode, val, line_number, format);
	return (format);
}


/**
 *execute - helps find appropriate function for the opcode
 *@opcode: character pointer to opcode
 *@val: pointer to character argument of opcode
 *@line_number: integer element value
 *@format: format specifier
 *Return: void
 */
void execute(char *opcode, char *val, int line_number, int format)
{
	int a = 0;
	int flag;

	instruction_t build[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"nop", f_nop},
		{"swap", f_swap},
		{"add", f_add},
		{"sub", f_sub},
		{"div", f_div},
		{"mod", f_mod},
		{"mul", f_mul},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, a = 0; build[a].opcode != NULL; a++)
	{
		if (strcmp(opcode, build[a].opcode) == 0)
		{
			c_func(build[a].f, opcode, val, line_number, format);
			flag = 0;
		}
	}
	if (flag == 1)
		print_err(3, line_number, opcode);
}

/**
 *c_func - function that calls the required function
 *@func: function
 *@opc: character pointer to opcode
 *@valc: represents numeric value
 *@line_number: value to element
 *@format: format specifier
 *Return: void
 */
void c_func(opc_func func, char *opc, char *valc, int line_number, int format)
{
	stack_t *node;
	int flag;
	int a = 0;

	flag = 1;
	if (strcmp(opc, "push") == 0)
	{
		if (valc != NULL && valc[0] == '-')
		{
			valc = valc + 1;
			flag = -1;
		}
		if (valc == NULL)
			print_err(5, line_number);
		for (a = 0; valc[a] != '\0'; a++)
		{
			if (isdigit(valc[a]) == 0)
				print_err(5, line_number);
		}
		node = create(atoi(valc) * flag);
		if (format == 0)
			func(&node, line_number);
		if (format == 1)
			add_queue(&node, line_number);
	}
	else
		func(&head, line_number);
}
