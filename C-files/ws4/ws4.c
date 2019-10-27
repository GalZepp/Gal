#include <stdio.h> /* printf, getchar */
#include <stdlib.h> /* system */
#include <assert.h> /* assert */

#define FAIL -1
#define ESC 27

typedef void(*ptr_table)(unsigned int);

/********** Disable/Enable terminal buffering ******/
int DisableTerminalBuffer()
{
	return system("stty -icanon -echo");
}

int EnableTerminalBuffer()
{
	return system("stty icanon echo");
}


/********** if/else *******/
int PrintAorTWithIf()
{
	int input = 0;

	if (FAIL == DisableTerminalBuffer())
	{
		return FAIL;
	}

	while (ESC != input)
	{
		input = getchar();

		if ('A' == input)
		{
			printf("A is pressed\n");
		}

		if ('T' == input)
		{
			printf("T is pressed\n");
		}
	}

	if (FAIL == EnableTerminalBuffer())
	{
		return FAIL;
	}

	return 0;
}

/*********** Switch **********/
int PrintAorTWithSwitch()
{
	int input = 0;

	if (FAIL == DisableTerminalBuffer())
	{
		return FAIL;
	}

	while (ESC != input)
	{
		input = getchar();

		switch (input)
		{
			case 'A' :
				printf("A is pressed\n");
				break;
			case 'T' :
				printf("T is pressed\n");
				break;
		}
	}

	if (FAIL == EnableTerminalBuffer())
	{
		return FAIL;
	}

	return 0;

}

/************* LUT ***********/
void PrintChar(unsigned int input)
{
	printf("%c is pressed\n", input);
}

void CreateLUT(ptr_table *func_table)
{
	int i = 0;

	assert(func_table);

	for (i = 0; 256 > i; ++i)
	{
		if ('A' == i || 'T' == i)
		{
			func_table[i] = PrintChar;
		}
		else
		{
			func_table[i] = NULL;
		}
	}
}

int PrintAorTWithLUT()
{
	int input = 0;
	ptr_table func_table[256];

	if (FAIL == DisableTerminalBuffer())
	{
		return FAIL;
	}

	CreateLUT(func_table);

	while (ESC != input)
	{
		input = getchar();

		if (func_table[input])
		{
			func_table[input](input);
		}
	}

	if (FAIL == EnableTerminalBuffer())
	{
		return FAIL;
	}

	return 0;
}

int main (int argc, char **argv)
{
	int test_num = 0;

	if (1 < argc)
	{
		test_num = atoi(argv[1]);
	}

	switch (test_num)
	{	
		case 1 :
			PrintAorTWithIf();
			break;
		case 2 :
			PrintAorTWithSwitch();
			break;
		case 3 :
			PrintAorTWithLUT();
			break;
	}

	return 0;
}
