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

void RmSpacesBegining(char *str)
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
}


void RmSpaces(char *str)
{
	char *space_runner = NULL;
	char *char_runner = NULL;

	assert(str);

	if (IsSpace(str))
	{
		RmSpacesBegining(str);
	}
	
	space_runner = str;
	char_runner = str;
	while (*char_runner && *space_runner)
	{
		space_runner = FindSpace(space_runner); 
		++space_runner;

		if (!IsSpace(space_runner))
		{
			continue;
		}
		else
		{
			char_runner = space_runner; char_runner = FindChar(char_runner);
			
			while (!IsSpace(char_runner) && *char_runner)
			{
				*space_runner = *char_runner;
				*char_runner = ' ';
				++space_runner;
				++char_runner;
			}
		}
	}

	space_runner = '\0';
}


int main ()
{
	char str[50] = {' ', ' ', '\t', '1', '2', '3', ' ', '\t', 's', 'a', 'b', '\0'};

	printf("Before Rm = aaaa%s000\n", str);
	RmSpaces(str);
	printf("After Rm = aaaa%s000\n", str);

	return 0;
}
