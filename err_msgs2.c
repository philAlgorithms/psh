#include "program.h"

char *error_126(char **args);
char *error_127(char **args);

/**
 * error_126 - Creates an error message for permission denied failures.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_126(char **args)
{
	char *error, *hist_string;
	int len;

	hist_string = _itoa(hist);
	if (!hist_string)
		return (NULL);

	len = _stringlen(name) + _stringlen(hist_string) + _stringlen(args[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_string);
		return (NULL);
	}

	_stringcpy(error, name);
	_stringcat(error, ": ");
	_stringcat(error, hist_string);
	_stringcat(error, ": ");
	_stringcat(error, args[0]);
	_stringcat(error, ": Permission denied\n");

	free(hist_string);
	return (error);
}

/**
 * error_127 - Creates an error message for command not found failures.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_127(char **args)
{
	char *error, *hist_string;
	int len;

	hist_string = _itoa(hist);
	if (!hist_string)
		return (NULL);

	len = _stringlen(name) + _stringlen(hist_string) + _stringlen(args[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_string);
		return (NULL);
	}

	_stringcpy(error, name);
	_stringcat(error, ": ");
	_stringcat(error, hist_string);
	_stringcat(error, ": ");
	_stringcat(error, args[0]);
	_stringcat(error, ": not found\n");

	free(hist_string);
	return (error);
}
