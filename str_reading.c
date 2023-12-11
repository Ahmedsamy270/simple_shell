#include "simple_shell.h"

/**
 * str_reading - is a function that reading the line from the stream
 * Return: Pointer To The Readed Line
 */

char *str_reading(void)
{
	int chr, i = 0;
	int buffer = 1024;
	char *ptrline = malloc(sizeof(char) * buffer);

	if (ptrline == NULL)
	{
		fprintf(stderr, "error in str_reading at malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		chr = getchar();
		if (chr == EOF)
		{
			free(ptrline);
			exit(EXIT_SUCCESS);
		}
		else if (chr == '\n')
		{
			ptrline[i] = '\0';
			return (ptrline);
		}
		else
		{
			ptrline[i] = chr;
		}
		i++;
		if (i >= buffer)
		{
			buffer += buffer;
			ptrline = realloc(ptrline, buffer);
			if (ptrline == NULL)
			{
				fprintf(stderr, "error in str_reading.c at realloc");
				exit(EXIT_FAILURE);
			}
		}
	}

}
