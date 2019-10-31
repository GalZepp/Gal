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
/*
	if (Strlen(str1) > Strlen(str2))
	{
		return 1;
	}
	
	if (Strlen(str2) > Strlen(str1))
	{
		return -1;
	}
*/
	while ((*str1 == *str2) && *str1)
	{
		++str1;
		++str2;
	}
	
	return (*str1 - *str2);
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


char *Strcat(char *dest, const char *src)
{
	char *dest_runner = NULL;

	assert(dest);
	assert(src);
	
	dest_runner = dest;

	dest_runner = GetToEnd(dest_runner);
	dest_runner = Strcpy(dest_runner, src);

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

/************************* Strstr ****************************/

int main ()
{
	return 0;
}
