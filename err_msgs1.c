#include "program.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
/**
 * error_env - Creates an error message for program_env errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_env(char **args)
{
	char *error, *hist_string;
	int len;

	hist_string = _itoa(hist);
	if (!hist_string)
		return (NULL);

	args--;
	len = _stringlen(name) + _stringlen(hist_string) + _stringlen(args[0]) + 45;
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
	_stringcat(error, ": Unable to add/remove from environment\n");

	free(hist_string);
	return (error);
}

/**
 * error_1 - Creates an error message for program_alias errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_1(char **args)
{
	char *error;
	int len;

	len = _stringlen(name) + _stringlen(args[0]) + 13;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_stringcpy(error, "alias: ");
	_stringcat(error, args[0]);
	_stringcat(error, " not found\n");

	return (error);
}

/**
 * error_2_exit - Creates an error message for program_exit errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_2_exit(char **args)
{
	char *error, *hist_string;
	int len;

	hist_string = _itoa(hist);
	if (!hist_string)
		return (NULL);

	len = _stringlen(name) + _stringlen(hist_string) + _stringlen(args[0]) + 27;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_string);
		return (NULL);
	}

	_stringcpy(error, name);
	_stringcat(error, ": ");
	_stringcat(error, hist_string);
	_stringcat(error, ": exit: Illegal number: ");
	_stringcat(error, args[0]);
	_stringcat(error, "\n");

	free(hist_string);
	return (error);
}

/**
 * error_2_cd - Creates an error message for program_cd errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_2_cd(char **args)
{
	char *error, *hist_string;
	int len;

	hist_string = _itoa(hist);
	if (!hist_string)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
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
	if (args[0][0] == '-')
		_stringcat(error, ": cd: Illegal option ");
	else
		_stringcat(error, ": cd: can't cd to ");
	_stringcat(error, args[0]);
	_stringcat(error, "\n");

	free(hist_string);
	return (error);
}

/**
 * error_2_syntax - Creates an error message for syntax errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_2_syntax(char **args)
{
	char *error, *hist_string;
	int len;

	hist_string = _itoa(hist);
	if (!hist_string)
		return (NULL);

	len = _stringlen(name) + _stringlen(hist_string) + _stringlen(args[0]) + 33;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_string);
		return (NULL);
	}

	_stringcpy(error, name);
	_stringcat(error, ": ");
	_stringcat(error, hist_string);
	_stringcat(error, ": Syntax error: \"");
	_stringcat(error, args[0]);
	_stringcat(error, "\" unexpected\n");

	free(hist_string);
	return (error);
}
