#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

void actmode(void);
void non_actmode(void);
char *line_reading(void);
char **line_div(char *line);
int arg_exe(char **arg);
int make_proc(char **arg);
char *str_reading(void);
int mycd(char **arg);
int myexit(char **arg);
int myenv(char **arg);
int myhelp(char **arg);

#endif
