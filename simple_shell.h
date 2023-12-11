#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define TOKEN_DELIM " \t\r\n\a\""
extern char **environ;

void actmode(void);
void non_actmode(void);
char *line_reading(void);
char **line_div(char *line);
int arg_exe(char **arg);
int make_proc(char **arg);
char *str_reading(void);
int own_cd(char **arg);
int own_exit(char **arg);
int own_env(char **arg);
int own_help(char **arg);

#endif
