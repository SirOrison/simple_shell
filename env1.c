#include "main.h"

/**
 * cmp_env_name - function that compares env varibles names
 * wit the name passed
 * @nenv: name of the environment variable
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are
 */

int cmp_env_name(const char *nenv, const char *name)
{
	int j;

	for (j = 0; nenv[j] != '='; j++)
	{
		if (nenv[j] != name[j])
			return (0);
	}
	return (j + 1);
}


/**
 * _getenv - function that get an environment variable
 * @name: name of the environment variables
 * @_environ: environment variable
 * Return: value of the environment variables if found or NULL
 */

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int R, D;

	ptr_env = NULL;
	D = 0;

	for (R = 0; _environ[R]; R++)
	{
		D = cmp_env_name(_environ[R], name);
		if (D)
		{
			ptr_env = _environ[R];
			break;
		}
	}
	return (ptr_env + D);
}


/**
 * _env - function that prints the environment variables
 * @datash: data relevant
 * Return: 1 on success
 */

int _env(data_shell *datash)
{
	int X, Y;

	for (X = 0; datash->_environ[X]; X++)
	{
		for (Y = 0; datash->_environ[X][Y]; Y++)
			;
		write(STDOUT_FILENO, datash->_environ[X], Y);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;
	return (1);
}
