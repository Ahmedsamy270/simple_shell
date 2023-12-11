#include "simple_shell.h"

/**
 * arg_exe - is a function that knowing if the command
 *is an exist one or a my comands
 * @arg: is the command and the flags
 * Return: -1 If Null Or Direct The Command To Another Process
 */

int arg_exe(char **arg)
{
	char *exist_func[] = {"cd", "env", "exit", "help"};

	int (*my_func[])(char **) = {&own_cd, &own_env, &own_exit, &own_help};

	int i = 0;

	if (arg[0] == NULL)
	{
		return (-1);
	}
	for (; i < sizeof(exist_func) / sizeof(char *); i++)
	{
		if (strcmp(arg[0], exist_func[i]) == 0)
		{
			return ((my_func[i])(arg));
		}
	}
	return (make_proc(arg));
}
