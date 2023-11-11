#include "main.h"

/**
*read_line - function that reads commands
*
*Return: Nothing
*/

char *read_line(void)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t chars_read;
	char *shell = "Shell>$ ";

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, shell, _strlen(shell));

	chars_read = getline(&cmd, &n, stdin);
	if (chars_read == -1)
	{
		free(cmd);	
		return (NULL);
	}

	return (cmd);
}
