#include <stdio.h>/* printf */
#include <stdlib.h>/* malloc */
#include <ctype.h>/* tolower */
#include <assert.h>/* assert */

#define WORD_SIZE sizeof(size_t)
#define ALIVE 0
#define DEAD 1 
#define NEXT ((i + 1) % num_of_soldiers)


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

size_t Josephus(size_t num_of_soldiers)
{
	size_t list_of_soldiers[num_of_soldiers];
	size_t i = 0;
	size_t alive = num_of_soldiers;

	if (0 == num_of_soldiers)
	{
		return 0;
	}

	for (i = 0; i < num_of_soldiers; ++i)
	{
		list_of_soldiers[i] = ALIVE;	
	}
	
	i = 0;
	while (1 < alive)
	{
		i = i % num_of_soldiers;

		if (ALIVE == list_of_soldiers[i])
		{
			while (DEAD == list_of_soldiers[NEXT])
			{
				++i;
			}

			list_of_soldiers[NEXT] = DEAD;
			--alive;
		}

		++i;
	}

	for (i = 0; DEAD == list_of_soldiers[i]; ++i)
	{}

	return i + 1;
}


int main (int argc, char **argv, char **envp)
{
	int test = 0;

	if (1 < argc)
	{
		test = atoi(argv[1]);	

		if (1 == test)
		{
			BuffAndPrintEnvp(envp);
		}
		else if (2 == test && argv[2])
		{
			printf("Soldier alive is = %lu\n", Josephus(atoi(argv[2])));
		}
		else
		{
			printf("Wrong input\n");
		}
	}

	return 0;
}
