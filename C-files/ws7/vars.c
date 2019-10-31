#include <stdio.h> 


void bar_function()
{
	unsigned int stop_now;
	while (!stop_now)
	{
		printf("Hello, world!\n");
		printf("stop now = %d\n", stop_now);
	}
}
