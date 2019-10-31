#include <stdio.h> 
#include <unistd.h>

extern unsigned int stop_now = 0;
extern void bar_function(void);

int main ()
{
	while (1) 
	{
		bar_function();
		sleep(3);
		stop_now = 1;
	}

	return 0;
}
