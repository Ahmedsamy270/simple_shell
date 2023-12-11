#include "simple_shell.h"

/**
 * line_reading - is a function that reads from stdin
 * Return: Pointer to the line
 */
char *line_reading(void)
{
	char *ptrline = NULL;
	size_t buffer = 0;

	if (getline(&ptrline, &buffer, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(ptrline);
			exit(EXIT_SUCCESS);
		}
		else
		{
		free(ptrline);
		perror("error in line_reading.c at stdin");
		exit(EXIT_FAILURE);
		}
	}
	return (ptrline);
}
