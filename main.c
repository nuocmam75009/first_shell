#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "(Eshell) $";
    char *lineptr;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";

    /* deaclaring the void variable */
    (void)ac;

    /* Loop for the prompt */
    while (1)
    {
    printf("%s", prompt);
    nchars_read = getline(&lineptr, &n, stdin);
    /* check if the getline function failed or reached the EOF or if user used CTRL + D */

        if (nchars_read == -1)
        {
        printf("Exiting shell....\n");
        return (-1);
        }

        /* allocate space for a copy of the lineptr */
        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy == NULL)
            {
                perror("tsh: memory allocation error");
                return (-1);
            }
            /* copy lineptr to lineptr_copy */
            strcpy(lineptr_copy, lineptr);

        /* split lineptr into an array of words
        & calculate the total number of tokens */
        token = strtok(lineptr, delim);

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        /* allocate space for the array of strings */
        argv = malloc(sizeof(char *) * num_tokens);

        /* store each token in the argv array*/
        token = strtok(lineptr_copy, delim);

        for (int i = 0; token != NULL; i++)
            {
                argv[i] = malloc(sizeof(char) * strlen(token));
                strcpy(argv[i], token);

                token = strtok(NULL, delim);
            }
            argv[i] = NULL;

    printf("%s\n", lineptr);

    /* free memory allocated for the lineptr*/
    free(lineptr);

    }
    return (0);
}