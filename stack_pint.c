#include "monty.h"

/**
 * stack_pint - prints all elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%u\n", (*stack)->n);
}
