#include "simple_shell.h"

/**
 * line_div - is a function that diivding the string into a multi strings
 * @line: is the line of the string needed to be divided
 * Return: Pointer To Arrptr
 */

char **line_div(char *line)
{
	int buffer = 64;
	char **arrptr = malloc(buffer * sizeof(char *));
	char *ptr;
	int i = 0;

	if (!arrptr)
	{
		fprintf(stderr, "error in line_div in allocat memory\n");
		exit(EXIT_FAILURE);
	}
	ptr = strtok(line, TOKEN_DELIM);
	for (i = 0; ptr != NULL; i++)
	{
		if (ptr[0] == '#')
		{
			break;
		}
		arrptr[i] = ptr;
		if (i >= buffer)
		{
			buffer += buffer;
			arrptr = realloc(arrptr, buffer * sizeof(char *));
			if (!arrptr)
			{
				fprintf(stderr, "error in line_div in realloc memory\n");
				exit(EXIT_FAILURE);
			}
		}
		ptr = strtok(NULL, TOK_DELIM);
	}
	arrptr[i] = NULL;
	return (arrptr);
}
