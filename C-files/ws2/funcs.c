#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <stdlib.h> /* atoi */

static char *GotoLastChar(char *str)
{
	while (*str)
	{
		++str;
	}

	return --str;
}


int IsPalindrome(const char *str)
{
	char *start = NULL;
	char *end = NULL;

	start = (char *)str;
	end = (char *)str;

	end = GotoLastChar(end);

	while ((*start == *end) && (end > start))
	{
		++start;
		--end;
	}

	if (start >= end)
	{
		return 1;/* 1 means palindrome */
	}

	return 0;
}

void DivOfSevenBoom(int from, int to)
{
	while (from != to)
	{

		if (0 == from % 7)
		{
			printf("BOOM\n");
		}
		else
		{
			printf("%d\n", from);
		}

		++from;
	}
}

void IntSwap(int *num1, int *num2)
{
	*num1 = *num1 + *num2;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}

int main (int argc, char **argv)
{
	int test_num = 0;
	char *str = NULL;
	int from = 0;
	int to = 0;
	int num1 = 0;
	int num2 = 0;

	if (argc < 3)
	{
		printf("The program needs 2 arguments\n");
	}
	else
	{
		test_num = atoi(argv[1]);
	}
	
	if (1 == test_num)
	{
		str = argv[2];

		if (IsPalindrome(str)) 
		{
			printf("%s is a palindrome.\n", str);
		}
		else
		{
			printf("%s is not a palindrome.\n", str);
		}
	}

	if (2 == test_num)
	{
		from = atoi(argv[2]);
		to = atoi(argv[3]);

		DivOfSevenBoom(from, to);
	}
		
	if (3 == test_num)
	{
		num1 = atoi(argv[2]);
		num2 = atoi(argv[3]);
		
		printf("before the swap\n");
		printf("num1 = %d\n", num1);
		printf("num2 = %d\n", num2);
		
		IntSwap(&num1, &num2);

		printf("after the swap\n");
		printf("num1 = %d\n", num1);
		printf("num2 = %d\n", num2);
	}

	return 0;
}
