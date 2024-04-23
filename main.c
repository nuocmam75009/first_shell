#include "main.h"

extern char **environ; /* environment variable */

int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $ "; 
	char *lineptr = NULL;
	ssize_t nchars_read = 0;
	/* Create a loop for the shell's prompt */
	while (1)
	{
		/*appel à read_prompt*/
		if (read_prompt(prompt, &nchars_read, &lineptr) <= -1)
		{
			return (-1);
		}
		tokenize(lineptr);
	}
	/* free up allocated memory */
	//free(lineptr);

	return (0);
}
