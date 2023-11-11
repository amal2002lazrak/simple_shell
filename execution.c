#include "main.h"

/**
*free_cmd - a function to free the memory
*@cmd: the memory to be freed
*/

void free_cmd(char **cmd)
{
	int j;

	if (cmd == NULL)
		return;

	for (j = 0; cmd[j]; j++)
	{
		free(cmd[j]);
		cmd[j] = NULL;
	}

	free(cmd), cmd = NULL;
}

/**
*execmd - a function that executes commands
*@cmd: command to be executed
*@argv: program's arguments
*
*Return: exit status of the executed command
*/

int execmd(char **cmd, char **argv)
{
	pid_t ch;
	int status;

	ch = fork();
	if (ch == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			free_cmd(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(ch, &status, 0);
		free_cmd(cmd);
	}
	return (WEXITSTATUS(status));
}
