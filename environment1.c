#include "main.h"

/**
 * cmp_env_name - compares environment variables names
 * with the name passed.
 * @nenv: the name of the environment variable
 * @name: the name passed
 *
 * Return: is  0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - it get an environment variable
 * @name: the name of the environment variable
 * @_environ: the environment variable
 *
 * Return: the  value of the environment variable if is found.
 * In other case, it returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* it initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* it compare all environment variables */
	/* environment is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If the name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - it prints the evironment variables
 *
 * @datash:the  data relevant.
 * Return: 1 is on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
