#include "monty.h"

/**
 * stack_swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
