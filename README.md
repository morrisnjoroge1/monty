0x19. C - Stacks, Queues - LIFO, FIFO Monty language - is a scripting language that is first compiled into Monty byte codes. - relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files. Files containing Monty byte codes usually have the .m extension. Monty byte code files can contain blank lines.

/The monty program/

Usage: monty file where file is the path to the file containing Monty byte code If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file , followed by a new line, and exit with the status EXIT_FAILURE where is the name of the file If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction , followed by a new line, and exit with the status EXIT_FAILURE where is the line number where the instruction appears. Line numbers always start at 1 The monty program runs the bytecodes line by line and stop if either: it executed properly every line of the file it finds an error in the file an error occured If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE. You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

/The push opcode/

The opcode push pushes an element to the stack.

Usage: push where is an integer if is not an integer or if there is no argument given to push, print("L<line_number>: usage: push integer\n") and exit (EXIT_FAILURE) where is the line number in the file. Use atoi function.

/The pall opcode/ The opcode pall prints all the values on the stack, starting from the top of the stack. Usage: pall

/The pint opcode/ The opcode pint prints the value at the top of the stack, followed by a new line. Usage: pint If the stack is empty, print ("L<line_number>: can't pint, stack empty\n"), and exit(EXIT_FAILURE)

/The pop opcode/ The opcode pop removes the top element of the stack. Usage: pop If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

/The swap opcode/ The opcode swap swaps the top two elements of the stack. Usage: swap If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

/The add opcode/ The opcode add adds the top two elements of the stack. Usage: add If the stack contains less than two elements, print the error message L<line_number> can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

/The nop opcode/ The opcode nop doesn’t do anything. Usage: nop

/The sub opcode/ The opcode sub subtracts the top element of the stack from the second top element of the stack. Usage: sub If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

/The div opcode/ The opcode div divides the second top element of the stack by the top element of the stack. Usage: div If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

/The mul opcode/ The opcode mul multiplies the second top element of the stack with the top element of the stack. Usage: mul If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

/The mod opcode/ The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack. Usage: mod If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

/The pchar opcode/ The opcode pchar prints the char at the top of the stack, followed by a new line. Usage: pchar The integer stored at the top of the stack is treated as the ascii value of the character to be printed If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE

/The pstr opcode/ The opcode pstr prints the string starting at the top of the stack, followed by a new line. Usage: pstr The integer stored in each element of the stack is treated as the ascii value of the character to be printed The string stops when either: the stack is over the value of the element is 0 the value of the element is not in the ascii table If the stack is empty, print only a new line

/The rotl opcode/ The opcode rotl rotates the stack to the top. Usage: rotl The top element of the stack becomes the last one, and the second top element of the stack becomes the first one

/The rotr opcode/ The opcode rotr rotates the stack to the bottom. Usage: rotr The last element of the stack becomes the top element of the stack

/The stack opcode/ The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program. Usage: stack

/The queue opcode/ The opcode queue sets the format of the data to a queue (FIFO). Usage: queue

note: When switching mode: The top of the stack becomes the front of the queue The front of the queue becomes the top of the stack
