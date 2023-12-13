#include "simple_shell.h"

/**
 * mycd - is a function that can move btween the directories in simple shell
 * @arg: is an arguments that recived to take the path
 * Return: 1 If Success
 */

int mycd(char **arg)
{
	if (arg[1] == NULL)
	{
		fprintf(stderr, "need argument for the command \"cd\"\n");
	}
	else
	{
		if (chdir(arg[1]) != 0)
		{
			perror("Error");
		}
	}
	return (-1);
}

/**
 * myhelp - is a function that display help message on prompt at simple shell
 * @arg: is an argument to take but it will be voided
 * Return: 1 If Success
 */

int myhelp(char **arg)
{
	(void)arg;
	printf("my simple shell help:\n");
	printf("those are my functions in simple shell :\n");
	printf("1.cd: to move between directories\n");
	printf("2.env: to display the enviroment variable\n");
	printf("3.help: to display the help message\n");
	printf("4.exit: to exit simple shell\n");
	return (-1);
}

/**
 * myenv - is a funcion to display the enviroment variables
 * @arg: is an argument to take but it will be voided
 * Return: 1 If Success
 */

int myenv(char **arg)
{
	int i;
	(void)arg;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (-1);
}

/**
 * myexit - is a function that used in simple shell so it can exit the program
 * @arg: is an argument to take but it will be voided
 * Return: 1 If Success
 */

int myexit(char **arg)
{
	(void)arg;
	exit(EXIT_SUCCESS);
}
