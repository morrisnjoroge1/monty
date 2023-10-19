#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line counter
* @file: poiner to monty file
* @command: line content
* Return: 1 on success or 0 otherwise
*/
int execute(char *command, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
{"pop", f_pop},
{"swap", f_swap},
{"add", f_add},
{"nop", f_nop},
{"sub", f_sub},
{"div", f_div},
{"mul", f_mul},
{"mod", f_mod},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{"queue", queue},
{"stack", stack},
{NULL, NULL}
};
unsigned int a = 0;
char *opc;

opc = strtok(command, " \n\t");
if (opc && opc[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[a].opcode && opc)
{
if (strcmp(opc, opst[a].opcode) == 0)
{	opst[a].f(stack, counter);
return (0);
}
a++;
}
if (opc && opst[a].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opc);
fclose(file);
free(command);
free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}
