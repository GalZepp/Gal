#include <stdio.h>/* printf */
#include <assert.h>/* assert */
#include <stdlib.h>/* malloc */

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



char *Strdup(const char *str)
{
	char *dest = NULL;

	assert(str);
	
	dest = (char *)malloc(Strlen((char *)str) + 1);
	
	return Strcpy(dest, str);
}


int main ()
{
	char *src = "@gmail.com";
	char *dest = NULL;
	char *address;
	
	if (*address)
	{
		dest = Strdup(src);
		printf("*dest = %c\n", *dest);
	}

	free(dest);

	printf("*dest = %c\n", *dest);

	return 0;
}
