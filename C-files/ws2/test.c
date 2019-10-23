#include <stdio.h> /* printf */
#include <stdlib.h>/* malloc */
#include <assert.h> /* assert */

int IsSpace(char *ch)
{
	assert(ch);

	if ((' ' == *ch) || ('\t' == *ch))
	{
		return 1;	
	}

	return 0;
}

char *FindSpace(char *str)
{
	char *space_runner = NULL;
	
	assert(str);

	space_runner = str;
	while (!IsSpace(space_runner))
	{
		++space_runner;	
	}

	return space_runner;
}

char *FindChar(char *str)
{
	char *runner = NULL;

	assert(str);

	runner = str;

	while (IsSpace(runner))
	{
		++runner;
	}
	
	return runner;
}


char *WritingOnSpaces(char *str)
{
	char *first_char = NULL;

	assert(str);

	first_char = FindChar(str);

	while (!IsSpace(first_char) && *first_char)
	{
		*str = *first_char;
		*first_char = ' ';
		++str;
		++first_char;
	}

	*str = *first_char;

	return str;
}

char *FindLastSpace(char *str)
{
	assert(str);

	while(IsSpace(str))
	{
		--str;
	}

	return str;
}

void RmSpaces(char *str)
{
	char *space_runner = NULL;

	assert(str);

	if (IsSpace(str))
	{
		str = WritingOnSpaces(str);
	}
	
	space_runner = str;

	while (*space_runner)
	{
		space_runner = FindSpace(space_runner); 
		++space_runner;

		if (IsSpace(space_runner))
		{
			space_runner = WritingOnSpaces(space_runner);
		}
	}
 	--space_runner;
	--space_runner;
	space_runner = FindLastSpace(space_runner);
	space_runner = '\0';

}


int main ()
{
	char str[50] = {' ', ' ', '\t', '1', '2', '3', ' ', '\t', 's', 'a', 'b', '\t', ' ', ' ', '1', '2', '3', ' ', ' ', '\0'};

	printf("Before Rm = aaaa%s000\n", str);
	RmSpaces(str);
	printf("After Rm = aaaa%s000\n", str);

	return 0;
}
