#include "main.h"

size_t _strspn(const char *s1, const char *s2);
char *_strchr(const char *s, int c);
size_t _strcspn(const char *s1, const char *s2);

/**
 * _strtok - breaks str into tokens and terminates the end
 * Delimiter - chars at start and end
 * @str: tokenize str
 * @delim: delimit srt str
 * Return: token
 **/
char *_strtok(char *str, const char *delim)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + _strspn(p, delim);
	p = str + _strcspn(str, delim);
	if (p == str)
		return (p = 0);
	p = *p ? *p = 0, p + 1 : 0;
	return (str);
}

/**
 * _strcspn - computes max str length
 * @s1: str to check
 * @s2: comparison str
 * Return: seg len
 **/

size_t _strcspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
			return (ret);
		s1++, ret++;
	}
	return (ret);
}

/**
 * _strspn - finds max len of str
 * @s1: first str
 * @s2: second delinit str
 * Return: segment len
 **/

size_t _strspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1 && _strchr(s2, *s1++))
		ret++;
	return (ret);
}

/**
 * _strchr - ﬁrst c occurrence of c
 * @s: str
 * @c: char
 * Return: char pointe
 **/
char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}