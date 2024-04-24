#include "main.h"

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
			/* free(prompt);
			free(nchars_read);
			free(lineptr); */
			return (-1);
		}
		tokenize(lineptr);

		if (read_prompt(prompt, &nchars_read, &lineptr) == 0)
		{
			exec_prompt(*prompt);

			return (0);
		}
	}
	/* free up allocated memory */
	free(lineptr);

	return (0);
}
