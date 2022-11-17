#include "program.h"

/**
 * _strlen - gets the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	size_t len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * tok_size - Locates the delimiter index marking the end
 *             of the first token contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token pointed to be str.
 */
int tok_size(char *str, char *delim)
{
	int size = 0, i = 0;

	while (str[i] != *delim && str[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

/**
 * tok_count - Counts the number of delimited
 *                words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */
int tok_count(char *str, char *delim)
{
	int i, num = 0, len = 0;

	len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != *delim)
		{
			num++;
			i += tok_size(str + i, delim);
		}
	}

	return (num);
}

/**
 * _stringtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_stringtok(char *line, char *delim)
{
	char **tokens;
	int i = 0, num, n, token_length, l;

	num = tok_count(line, delim);
	if (num == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (num + 2));
	if (!tokens)
		return (NULL);

	for (n = 0; n < num; n++)
	{
		while (line[i] == *delim)
			i++;

		token_length = tok_size(line + i, delim);

		tokens[n] = malloc(sizeof(char) * (token_length + 1));
		if (!tokens[n])
		{
			for (i -= 1; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}

		for (l = 0; l < token_length; l++)
		{
			tokens[n][l] = line[i];
			i++;
		}
		tokens[n][l] = '\0';
	}

	tokens[n] = NULL;
	tokens[n + 1] = NULL;

	return (tokens);
}
