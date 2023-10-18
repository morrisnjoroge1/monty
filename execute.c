"monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line counter
* @file: poiner to monty file
* @content: line content
* Return: 1 on success or 0 on failure 
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
execute_t func[] = {
{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
{"pop", f_pop},
{"swap", f_swap},
{"add", f_add},
{"nop", f_nop},
{"sub", sub},
{"div", f_div},
{"mul", mul},
{"mod", mod},
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

opc = strtok(content, " \n\t");
if (opc && opc[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (func[a].opcode && opc)
{
if (strcmp(opc, func[a].opcode) == 0)
{func[a].f(stack, counter);
return (0);
}
i++;
}
if (opc && func[a].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opc);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}

