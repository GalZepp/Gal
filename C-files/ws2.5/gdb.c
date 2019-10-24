#include <stdio.h>/* printf */
#include <assert.h>/* assert */
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


int main ()
{
	char *src = "abcdefg";
	char *src1 = "123";
	char *dest = (char *)malloc(40);
	
	dest = Strcpy(dest, src1);
	dest = Strcat(dest, src);

	printf("dest = %s\n", dest);

	free(dest);
	dest = NULL;

	return 0;
}
