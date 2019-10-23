#include <stdio.h>/* printf */
#include <stdlib.h>/* malloc */
#include <ctype.h>/* tolower */
#include <assert.h>/* assert */

#define WORD_SIZE sizeof(size_t)

/*********** Print and Buff envp ******/

size_t PtrToPtrLen(char **str)
{
	char **runner = NULL;
	size_t counter = 0;

	assert(str);

	runner = str;

	while (*runner)
	{
		++counter;
		++runner;
	}

	return counter;
}

size_t Strlen(char *str)
{
	char *runner = NULL;
	size_t counter = 0;

	assert(str);

	runner = str;

	while (*runner)
	{
		++counter;
		++runner;
	}

	return counter;
}

char **EnvpBuffMemAlloc(char **envp)
{
	char **runner = NULL;
	char **buffer = NULL;
	char **buff_runner = NULL;

	assert(envp);

	runner = envp;

	buffer = (char **)malloc(PtrToPtrLen(runner) * WORD_SIZE);
	buff_runner = buffer;

	while (*runner)
	{
		*buff_runner = (char *)malloc(Strlen(*runner));
		++runner;
		++buff_runner;
	}

	return buffer;
}

void BuffAndPrintEnvp(char **envp)
{
	char **buffer = NULL;

	assert(envp);

	buffer = EnvpBuffMemAlloc(envp);
	
	while (*envp)
	{
		while (**envp)
		{
			**buffer = tolower(**envp);
			printf("%c", **buffer);
			++*envp;
			++*buffer;
		}

		printf("\n");
		++envp;
		++buffer;
	}
}
/*********** End of Envp ************/

int main (int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	BuffAndPrintEnvp(envp);

	return 0;
}
