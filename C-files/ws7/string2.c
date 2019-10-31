char *Strcpy(char *dest, const char *src)
{
	char *dest_runner = NULL;

	assert(src);
	assert(dest);
	
	dest_runner = dest;

	while (*src)
	{
		*dest_runner = *src;
		++src;
		++dest_runner;
	}
	
	*dest_runner = '\0';

	return dest;
}


char *Strncpy(char *dest, const char *src, size_t n)
{
	char *dest_runner = NULL;
	
	assert(dest);
	assert(src);

	dest_runner = dest;

	while (n && *src)
	{
		*dest_runner = *src;
		++src;
		++dest_runner;
		--n;
	}

	return dest;
}

int main ()
{
	return 0;
}
