#include "main.h"

/*
 * tokenize - split string to array of words
 * @lineptr : string to be split
 *
 *
 */
int getLenghtToken(char *lineptr, const char *delim);

int tokenize(char *lineptr)
{

	int num_tokens = 0;
	const char *delim = " \n";
	char *token = malloc(128 * sizeof(char *));
	char **argv;
	int i;

	if (!token)
	{
		fprintf(stderr, "Allocation error");
		return (-1);
	}
	num_tokens = getLenghtToken(lineptr, delim);

	argv = malloc(sizeof(char *) * (num_tokens + 1));

	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * 128);
		strcpy(argv[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	// argv[i] = NULL;
	free(argv);
	free(token);
}

int getLenghtToken(char *lineptr, const char *delim)
{

	char *buffer = malloc(sizeof(char) * 128);
	int num_tokens = 0;

	strcpy(buffer, lineptr);

	strtok(buffer, delim);
	while (buffer != NULL)
	{
		++num_tokens;
		strtok(NULL, delim);
	}
	return num_tokens;
}