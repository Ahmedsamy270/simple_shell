#include "simple_shell.h"

/**
 * actmode - is a function that workes in interactive mode
 * Return: Void
 */
void actmode(void)
{
	char *ptrline;
	char **arg;
	int report = -1;

	do {
		printf("my_shell$ ");
		ptrline = line_reading();
		arg = line_div(ptrline);
		report = arg_exe(arg);
		free(ptrline);
		free(arg);
		if (report >= 0)
		{
			exit(report);
		}
	} while (report == -1);
}
