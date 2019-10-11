#ifndef __String_H__
#define __String_H__

#include <stddef.h>/* size_t */

	size_t Strlen(const char *str);
	
	int Strcmp(const char *str1, const char *str2);

	char *Strcpy(char *dest, const char *src);

	char *Strncpy(char *dest, const char *src, size_t n);

	int Strcasecmp(const char *str1, const char *str2);

	char *Strchr(const char *str, int c);

	char *Strdup(const char *str);

	char *Strcat(char *dest, const char *src);

	char *Strncat(char *dest, const char *src, size_t n);

	char *Strstr(const char *haystack, const char *needle);

#endif /* __String_H__ */
