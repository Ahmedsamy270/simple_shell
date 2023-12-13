#include "simple_shell.h"

/**
 * arg_exe - is a function that knowing if the command
 *is an exist one or a my comands
 * @arg: is the command and the flags
 * Return: -1 If Null Or Direct The Command To Another Process
 */

int arg_exe(char **arg)
{
	char *myfuncarr[] = {"cd", "env", "exit", "help"};

	int (*myfunc[])(char **) = {&mycd, &myenv, &myexit, &myhelp};

	unsigned int i = 0;

	if (arg[0] == NULL)
	{
		return (-1);
	}
	for (; i < sizeof(myfuncarr) / sizeof(char *); i++)
	{
		if (strcmp(arg[0], myfuncarr[i]) == 0)
		{
			return ((myfunc[i])(arg));
		}

	}
	if (strcmp(arg[0], "exit") == 0)
	{
		return (0);
	}
	return (make_proc(arg));
}
