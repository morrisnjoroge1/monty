#ifndef MONTY_HEADER
#define MONTY_HEADER

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
I* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
stack_t *head = NULL;
typedef void (*op_func)(stack_t **, unsigned int);

/*ALL THE PROTOTYPES*/
void f_add(stack_t **neww, unsigned int line_number);
void f_div(stack_t **neww, unsigned int line_number);
void f_sub(stack_t **neww, unsigned int line_number);
void f_mod(stack_t **neww, unsigned int line_number);
void f_nop(stack_t **neww, unsigned int line_number);

void f_mul(stack_t **neww, unsigned int line_number);
void f_swap(stack_t **neww, unsigned int line_number);
void f_pint(stack_t **neww, unsigned int line_number);
void f_pop(stack_t **neww, unsigned int line_number);

void f_pchar(stack_t **neww, unsigned int line_number);
void f_pstr(stack_t **neww, __attribute__((unused))unsigned int line_number);
void rotl(stack_t **neww, __attribute__((unused))unsigned int line_number);
void rotr(stack_t **neww, __attribute__((unused))unsigned int line_number);

void add_queue(stack_t **neww, __attribute__((unused))unsigned int line_number);
void f_push(stack_t **neww, __attribute__((unused))unsigned int line_number);
void f_pall(stack_t **neww, unsigned int line_number);

void print_err(int error_num, ...);
void print_err1(int error_num, ...);
void print_err2(int error_num, ...);

void free_stack(void);
stack_t *create(int n);

void open_fl(char *sile_name);
void read_fl(FILE *pd);
int parse_line(char *buff, int line_number, int format);
void execute(char *opcode, char *val, int line_number, int format);
void c_func(op_func func, char *opc, char *valc, int line_number, int format);

#endif
