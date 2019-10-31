#include <stdio.h>

#include "g.h"


extern void foo();

int main ()
{
	
	printf("g_s = %d\n", g_s);
	foo();
	printf("++g_s = %d\n", g_s);

	return 0;
}
