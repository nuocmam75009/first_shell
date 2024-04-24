#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void execmd(char **argv);
char *get_location(char *command);
int stat(const char *pathname, struct stat *statbuf);
int read_prompt(char *prompt, ssize_t *nchars_read, char **lineptr);
extern char **environ;
int tokenize(char *lineptr);
int getLenghtToken(char *lineptr, const char* delim);

#endif