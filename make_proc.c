#include "simple_shell.h"

/**
 * make_proc - is a function that creats a new process
 * @arg: is an array of commands and flag
 * Return: On Error Print The Errors Or 1 If Success
 */

int make_proc(char **arg)
{
	int report;
	pid_t id;

	id = fork();
	if (id == -1)
	{
		perror("error on make_proc.c in the forking process");
	}

	if (id == 0)
	{
		if (execvp(arg[0], arg) == -1)
		{
			perror("error at make_proc.c in the id 0");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(id, &report, WUNTRACED);
		} while (!WIFEXITED(report) && !WIFSIGNALED(report));
	}
	return (-1);
}
