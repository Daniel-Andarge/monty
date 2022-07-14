#include "monty.h"

/**
 * isNum - checks if a string is a number
 * @str: string to check
 * Return: True(1), False(0)
 */
int isNum(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
		{
			if (str[i + 1] == '\0')
				return (0);
		}
		else if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}

/**
 * stack_push - adds an element to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void stack_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *end;

	if (mem.n == NULL || isNum(mem.n) == 0)
	{
		free_all(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_all(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(mem.n);

	if (mem.mode == STACK || (*stack) == NULL)
	{
		/* add node to the top */
		new->prev = NULL;
		new->next = *stack;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		/* add node to the end */
		for (end = *stack; end->next != NULL; end = end->next)
			;
		end->next = new;
		new->prev = end;
		new->next = NULL;
	}
}
