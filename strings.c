#include "main.h"

/**
 *_strdup - duplicates a string
 *@str: string to duplicate
 *
 *Return: pointer to duplicated stringvor NULL if it fails
*/

char *_strdup(char *str)
{
	char *strdp;
	unsigned int i, j;

	if (str == 0)
	return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{}
	strdp = (char *) malloc(sizeof(char) * (i + 1));

	if (strdp == 0)
	return (NULL);

	for (j = 0; j <= i; j++)
	strdp[j] = str[j];

	return (strdp);

}

/**
 *_strlen - returns the length of a string
 *@s: the string input
 *
 *Return: the lenght
*/

int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
