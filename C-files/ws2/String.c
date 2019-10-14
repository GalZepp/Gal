#include <stdio.h>/* printf */
#include <assert.h>/* assert */
#include <string.h>/* strlen */
#include <ctype.h>/* tolower */
#include <stdlib.h>/* malloc */

static char *GetToEnd(char *str)
{
	assert(str);

	while (*str)
	{
		++str;
	}

	return str;
}

/*************************************************************/

size_t Strlen(const char *str)
{
	size_t counter = 0;

	assert(str);

	while (*str)
	{
		++counter;
		++str;
	}

	return counter;
}


int Strcmp(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);

	while ((*str1 == *str2) && *str1)
	{
		++str1;
		++str2;
	}
	
	return (*str1 - *str2);
}


char *Strcpy(char *dest, const char *src)
{
	char *dest_runner = NULL;

	assert(src);
	assert(dest);
	
	dest_runner = dest;

	while (*src)
	{
		*dest_runner = *src;
		++src;
		++dest_runner;
	}
	
	*dest_runner = '\0';

	return dest;
}


char *Strncpy(char *dest, const char *src, size_t n)
{
	char *dest_runner = NULL;
	
	assert(dest);
	assert(src);

	dest_runner = dest;

	while (n && *src)
	{
		*dest_runner = *src;
		++src;
		++dest_runner;
		--n;
	}

	return dest;
}

int Strcasecmp(const char *str1, const char *str2)
{
	char *runner1 = NULL;
	char *runner2 = NULL;

	assert(str1);
	assert(str2);

	runner1 = (char *)str1;
	runner2 = (char *)str2;

	while (tolower(*runner1) == tolower(*runner2) && *runner1)
	{
		++runner1;
		++runner2;
	}
	
	return (tolower(*runner1) - tolower(*runner2));
}

char *Strchr(const char *str, int c)
{
	assert(str);

	while ((*str != c) && *str)
	{
		++str;
	}
	
	if (*str == '\0')
	{
		return NULL;
	}
	
	return (char *)str;
}


char *Strdup(const char *str)
{
	char *dest = NULL;

	assert(str);
	
	dest = (char *)malloc(Strlen((char *)str) + 1);
	
	return Strcpy(dest, str);
}

char *Strcat(char *dest, const char *src)
{
	char *dest_runner = NULL;

	assert(dest);
	assert(src);
	
	dest_runner = dest;
	dest_runner = GetToEnd(dest_runner);

	while (*src)
	{
		*dest_runner = *src;
		++src;
		++dest_runner;
	}

	dest_runner = '\0';

	return dest;
}

char *Strncat(char *dest, const char *src, size_t n)
{
	char *dest_runner = NULL;

	assert(dest);
	assert(src);

	dest_runner = dest;	
	dest_runner = GetToEnd(dest_runner);
	
	while (n && *src)
	{
		*dest_runner = *src;
		++dest_runner;
		++src;
		--n;
	}

	dest_runner = '\0';

	return dest;
}

/*************************************************************/

static int IsNeedle(const char *haystack, const char *needle)
{
	assert(haystack);
	assert(needle);

	while ((*needle == *haystack) && *needle)
	{
		++needle;
		++haystack;
	}

	if (*needle == '\0')
	{
		return 0;
	}

	return 1;
}


char *Strstr(const char *haystack, const char *needle)
{
	int no_match = 0;

	assert(haystack);
	assert(needle);

	no_match = IsNeedle(haystack, needle);
	while (no_match && *haystack)
	{
		++haystack;
		no_match = IsNeedle(haystack, needle);
	}

	if (no_match)
	{
		return NULL;
	}
	
	return (char *)haystack;
}

/*************************************************************/





















