#include "main.h"

/**
*get_token - function that tokenize a string into an array of tokens
*@line: the command to be tokenized
*
*Return: array of tokens
*/

char **get_token(char *line)
{
	char *tkn = NULL, *line_copy = NULL;
	char **arg = NULL;
	int count = 0, i = 0;

	if (line == NULL)
		return (NULL);
	line_copy = _strdup(line);
	tkn = strtok(line_copy, DELIM);
	if (tkn == NULL)
	{
		free(line), line = NULL;
		free(line_copy), line_copy = NULL;
		return (NULL);
	}

	while (tkn)
	{
		count++;
		tkn = strtok(NULL, DELIM);
	}
	free(line_copy), line_copy = NULL;
	arg = malloc(sizeof(char *) * (count + 1));
	if (!arg)
	{
		free(line), line = NULL;
		return (NULL);
	}
	tkn = strtok(line, DELIM);
	while (tkn)
	{
		arg[i] = _strdup(tkn);
		tkn = strtok(NULL, DELIM);
		i++;
	}
	free(line), line_copy = NULL;
	arg[i] = NULL;
	return (arg);
}
