#include "main.h"

/**
 * _strdup - is a function duplicates a str in the heap memory.
 *
 * @s: the type char pointer str
 *
 * Return: is duplicated str
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - it returns the lenght of a string.
 *
 * @s: the type char pointer
 *
 * Return: is always 0.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - it compare chars of strings
 *
 * @str: the input string.
 * @delim: the delimiter.
 *
 * Return: it is 1 if they are equals, 0 if they are not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - is a function that splits a string by some delimiter.
 *
 * @str: it input a string.
 * @delim: the delimiter.
 *
 * Return: the string to be splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store the first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store the last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching  end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking the loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing the delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - the function that defines if string passed is a number
 *
 * @s: is input string
 *
 * Return: it is 1 if string is an interger. 0 otherwise if not
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
