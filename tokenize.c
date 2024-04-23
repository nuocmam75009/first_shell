#include "main.h"

/*
 * tokenize - split string to array of words
 * @lineptr : string to be split
 * 
 * 
 */

int tokenize(char *lineptr)
{

        int num_tokens = 0;
        const char *delim = " \n";
        char *token = malloc(128 * sizeof(char*));
		if (!token) 
		{
			fprintf(stderr, "Allocation error");
			return(-1);
		}
		num_tokens = getLenghtToken(lineptr, delim);
		char **argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr, delim);
		int i = 0;
		while (token != NULL)
		{
			argv[i] = malloc(128 * sizeof(char*));
			strcpy(argv[i], token); 
			++i;
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
        execmd(argv);
		for (int i = 0 ; i < num_tokens; i++)
			free(argv[i]);
		free(argv);
        free(token);
}

int getLenghtToken(char *lineptr, char* delim) {
	char *buffer,token;
    int num_tokens = 0;
	strcpy(buffer,lineptr);
	
	token = strtok(buffer, delim);
	while (token != NULL){
        ++num_tokens;
		token = strtok(NULL, delim);
	}
	return num_tokens;
}
