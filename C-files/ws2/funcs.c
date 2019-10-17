#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <stdlib.h> /* atoi */

static void GotoLastChar(char *str)
{
	while (*str)
	{
		++str;
	}

	--str;
}


int IsPalindrome(const char *str)
{
	char *start = NULL;
	char *end = NULL;

	start = (char *)str;
	end = (char *)str;

	GotoLastChar(end);

	while ((*start == *end) && (end > start))
	{
		++start;
		--end;
	}

	if (start >= end)
	{
		return 1;
	}

	return 0;
}

int main (int argc, char **argv)
{
	int test_num = 0;
	
	if (argc < 2)
	{
		printf("The program needs 2 arguments");
	}

	test_num = atoi(argv[1]);

	if (1 == test_num)
	{
		if (IsPalindrome(argv[2]))
		{
			printf("%s is a plindrome.\n", argv[2]);
		}
		else
		{
			printf("%s is not a plindrome.\n", argv[2]);
		}
	}

	return 0;
}
