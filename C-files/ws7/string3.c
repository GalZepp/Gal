char *Strchr(const char *str, int c)
{
	assert(str);

	while ((*str != c) && *str)
	{
		++str;
	}
	
	if (*str == '\0')
	{
		return NULL;
	}
	
	return (char *)str;
}


char *Strdup(const char *str)
{
	char *dest = NULL;

	assert(str);
	
	dest = (char *)malloc(Strlen((char *)str) + 1);
	
	return Strcpy(dest, str);
}
