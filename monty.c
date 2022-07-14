#include "monty.h"

allocated_t mem;

/**
 * main - opens a Monty bytecode file and executes it
 * @argc: number of arguments, should be 2
 * @argv: array of command line arguments, should contain path to monty script
 * Return: Success(0), Error(EXIT_FAILURE)
 */
int main(int argc, char const *argv[])
{
	/* Checks for file arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* defaults format mode to stack */
	mem.mode = STACK;

	/* Attempts to open the file */
	mem.pScript = fopen(argv[1], "r");
	if (mem.pScript == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Executes the monty bytecode script */
	execute_script();
	return (0);
}
