#include <stdio.h>/* printf */
#include <assert.h>/* assert */

#define ALIVE 0
#define DEAD 1 
#define NEXT ((i + 1) % num_of_soldiers)

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

int main ()
{	
	printf("alive == %lu\n", Josephus(1)); 
	
	return 0;
}
