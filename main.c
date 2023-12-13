#include "simple_shell.h"

/**
 * main - is the main function for all simple shell project
 * Return: 0 On Success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		actmode();
	}
	else
	{
		 non_actmode();
	}
	return (0);
}
