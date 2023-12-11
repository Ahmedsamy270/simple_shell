#include "simple_shell.h"

/**
 * non_actmode - is a function that works in non interactive mode
 * Return: Void
 */

void non_actmode(void)
{
	char **arg;
	char *ptrline;
	int report = -1;

	do {
		ptrline = str_reading();
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
