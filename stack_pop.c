#include "monty.h"

/**
 * stack_pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *delete = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(delete);
	if (*stack != NULL)
		(*stack)->prev = NULL;
}
