#include "main.h"

int read_prompt(char *prompt, ssize_t *nchars_read, char *lineptr)
{
    size_t n = 0;

    printf("%s", prompt);
    *nchars_read = getline(lineptr, &n, stdin);
    /* check if the getline function failed or reached EOF or user use CTRL + D */
    if (*nchars_read == -1)
    {
        printf("Exiting shell....\n");
        return (-1);
    }

    return (0);
}