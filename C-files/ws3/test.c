#include <stdio.h>/* printf */
#include <stdlib.h>/* malloc */
#include <assert.h>/* assert */
#include <string.h>/* memset */




int main ()
{	
	int list[7] = {0};
	int count = 7;
	size_t i = 0;
	int sword = 1;


	while (count > 2)
	{
		while (0 != list[i % 7])		
		{
			++i;
		}
		if (sword)
		{
			list[i % 7] = 1;
			--count;
			sword = 0;
		}
		else
		{
			sword = 1;
			++i;
		}
		printf("count = %d\n", count);
		printf("sword = %d\n", sword);
	}

	printf("i = %lu\n", (i % 7));
	
	return 0;
}
