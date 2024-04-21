#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void execmd(char **argv);
char *get_location(char *command);
int stat(const char *pathname, struct stat *statbuf);