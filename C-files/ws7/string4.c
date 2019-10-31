static int IsNeedle(const char *haystack, const char *needle)
{
	assert(haystack);
	assert(needle);

	while ((*needle == *haystack) && *needle)
	{
		++needle;
		++haystack;
	}

	if (*needle == '\0')
	{
		return 0;
	}

	return 1;
}


char *Strstr(const char *haystack, const char *needle)
{
	int no_match = 0;

	assert(haystack);
	assert(needle);

	no_match = IsNeedle(haystack, needle);
	while (no_match && *haystack)
	{
		++haystack;
		no_match = IsNeedle(haystack, needle);
	}

	if (no_match)
	{
		return NULL;
	}
	
	return (char *)haystack;
}

/********************* End of Strstr *************************/

/********************* Strspn ************************/

size_t MatchChar(const char *haystack, const char *ch)
{
	char *hay_runner = NULL;

	assert(haystack);

	hay_runner = (char *)haystack;
	while (*hay_runner)
	{
		if (*ch == *hay_runner)
		{
			return 1;
		}
		++hay_runner;
	}

	return 0;
}


size_t Strspn(const char *haystack, const char *needle)
{
	size_t num_of_matchs = 0;
	char *hay_runner = NULL;

	assert(haystack);
	assert(needle);

	hay_runner = (char *)haystack;
	while (*hay_runner && MatchChar(needle, hay_runner))
	{
		++hay_runner;
		++num_of_matchs;
	}

	return num_of_matchs;
}

/****************** end of Strspn *******************/


