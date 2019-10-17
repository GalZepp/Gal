#include <string.h>/* strlen, strcmp ... */
#include <stdio.h>/* printf */
#include <stdlib.h>/* malloc */
#include <assert.h>/* assert */
#include <strings.h>/* strcasecmp */

#include "String.h"
#include "color.h"


static char *GetColor(int tests, int pass)
{
	if(pass == tests)
	{
		return GREEN"PASS ";
	}
	return RED"FAIL ";
}

char *strdup(const char *s);

/**************************************************************/
void TestStrlen()
{
    int tests = 4;
	int pass = 0;
	char *str1 = "";
	char *str2 = "abcdefd329942";
	char *str3 = "   abs   svjl 	sfl";
	char *str4 = " ** &&   		(()()	?><  ";
	
	if (Strlen(str1) == strlen(str1))
	{
		++pass;
	}
	
	if (Strlen(str2) == strlen(str2))
	{
		++pass;
	}
	
	if (Strlen(str3) == strlen(str3))
	{
		++pass;
	}
	
	if (Strlen(str4) == strlen(str4))
	{
		++pass;
	}
	
	printf(YELLOW "Test to Strlen() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}

void TestStrcmp()
{
   int tests = 8;
	int pass = 0;
	char *str1 = "";
	char *str2 = "abcdefd329942";
	char *str3 = "   abs   svjl 	sfl";
	char *str4 = " ** &&   		(()()	?><  ";
	char *str5 = "abcd";
	char *str6 = "abce";
	char *str7 = "abc";
	char *str8 = "abcz";
	
	if (Strcmp(str1, str1) == strcmp(str1, str1))
	{
		++pass;
	}
	
	if (Strcmp(str2, str2) == strcmp(str2, str2))
	{
		++pass;
	}
	
	if (Strcmp(str3, str3) == strcmp(str3, str3))
	{
		++pass;
	}
	
	if (Strcmp(str4, str4) == strcmp(str4, str4))
	{
		++pass;
	}
	
	if (Strcmp(str5, str6) == strcmp(str5, str6))
	{
		++pass;
	}
	
	if (Strcmp(str6, str5) == strcmp(str6, str5))
	{
		++pass;
	}
	
	if (Strcmp(str7, str8) == strcmp(str7, str8))
	{
		++pass;
	}
	printf("system = %d\n", strcmp(str7, str8));
	printf("mine = %d\n", Strcmp(str7, str8));

	if (Strcmp(str8, str7) == strcmp(str8, str7))
	{
		++pass;
	}
	printf("system = %d\n", strcmp(str7, str8));
	printf("mine = %d\n", Strcmp(str7, str8));

	printf(YELLOW "Test to Strcmp() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}

void TestStrcpy()
{
    int tests = 4;
	int pass = 0;
	char *src1 = "";
	char *src2 = "abcdefd329942";
	char *src3 = "   abs   svjl 	sfl";
	char *src4 = " ** &&   		(()()	?><  ";
	char *dest1 = (char *)malloc(50);
	char *dest2 = (char *)malloc(50);

	if (Strcmp(Strcpy(dest1, src1), src1) == Strcmp(strcpy(dest2 , src1), src1))
	{
		++pass;
	}
	
	if (Strcmp(Strcpy(dest1, src2), src2) == Strcmp(strcpy(dest2 , src2), src2))
	{
		++pass;
	}
	
	if (Strcmp(Strcpy(dest1, src3), src3) == Strcmp(strcpy(dest2 , src3), src3))
	{
		++pass;
	}
	
	if (Strcmp(Strcpy(dest1, src4), src4) == Strcmp(strcpy(dest2 , src4), src4))
	{
		++pass;
	}
	
	free(dest1); dest1 = NULL;
	free(dest2); dest2 = NULL;
	
	printf(YELLOW "Test to Strcpy() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}

void TestStrncpy()
{
    int tests = 5;
	int pass = 0;
	char *src1 = "";
	char *src2 = "abcdefd329942";
	char *src3 = "   abs   svjl 	sfl";
	char *src4 = " ** &&   		(()()	?><  ";
	
	char *dest1 = (char *)malloc(50);
	char *dest2 = (char *)malloc(50);
	memset(dest1, 0, 50);
	memset(dest2, 0, 50);
	
	if (!Strcmp(Strncpy(dest1, src1, 3), strncpy(dest2 , src1, 3)))
	{
		++pass;
	}
	
	if (!Strcmp(Strncpy(dest1, src2, 5), strncpy(dest2 , src2, 5)))
	{
		++pass;
	}
	
	if (!Strcmp(Strncpy(dest1, src2, 25), strncpy(dest2 , src2, 25)))
	{
		++pass;
	}
	
	if (!Strcmp(Strncpy(dest1, src3, 10), strncpy(dest2 , src3, 10)))
	{
		++pass;
	}
	
	if (!Strcmp(Strncpy(dest1, src4, 7), strncpy(dest2 , src4, 7)))
	{
		++pass;
	}
	
	free(dest1); dest1 = NULL;
	free(dest2); dest2 = NULL;
	
	printf(YELLOW "Test to Strncpy() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}

void TestStrcasecmp()
{
    int tests = 5;
	int pass = 0;
	char *str1 = "";
	char *str2 = "abcdefd329942";
	char *str3 = "  aBaCtT	KLabc ";
	char *str4 = "  aBaCtT  KLabc ";
	char *str5 = "abcd";
	char *str6 = "ABCD";
	char *str7 = "abc";
	char *str8 = "abce";
	
	if (Strcasecmp(str1, str1) == strcasecmp(str1, str1))
	{
		++pass;
	}
	
	if (Strcasecmp(str2, str2) == strcasecmp(str2, str2))
	{
		++pass;
	}
	
	if (Strcasecmp(str5, str6) == strcasecmp(str5, str6))
	{
		++pass;
	}
	
	if (Strcmp(str7, str8) == strcmp(str7, str8))
	{
		++pass;
	}
	
	if (Strcmp(str3, str4) == strcmp(str3, str4))
	{
		++pass;
	}

	printf(YELLOW "Test to Strcasecmp() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}


void TestStrchr()
{
	int tests = 6;
	int pass = 0;
	char c = 'd';
	char *str1 = "";
	char *str2 = "abcdefd329942";
	char *str3 = "  aBaCtT	KLabc ";
	char *str4 = "abcd";
	char *str5 = "ABCD";
	char *str6 = "abce";
	
	if (Strchr(str2, c) == strchr(str2, c))
	{
		++pass;
	}
	
	if (Strchr(str1, c) == strchr(str1, c))
	{
		++pass;
	}

	if (Strchr(str3, c) == strchr(str3, c))
	{
		++pass;
	}
	
	if (Strchr(str4, c) == strchr(str4, c))
	{
		++pass;
	}

	if (Strchr(str5, c) == strchr(str5, c))
	{
		++pass;
	}
	
	if (Strchr(str6, c) == strchr(str6, c))
	{
		++pass;
	}


	printf(YELLOW "Test to Strchar() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}

void TestStrdup()
{
	int tests = 4;
	int pass = 0;
	char *src1 = "";
	char *src2 = "abcdefd329942";
	char *src3 = "   abs   svjl 	sfl";
	char *src4 = " ** &&   		(()()	?><  ";


	if (Strcmp(Strdup(src1), src1) == Strcmp(strdup(src1), src1))
	{
		++pass;
	}
	
	if (Strcmp(Strdup(src2), src2) == Strcmp(strdup(src2), src2))
	{
		++pass;
	}
	
	if (Strcmp(Strdup(src3), src3) == Strcmp(strdup(src3), src3))
	{
		++pass;
	}
	
	if (Strcmp(Strdup(src4), src4) == Strcmp(strdup(src4), src4))
	{
		++pass;
	}
	
	
	printf(YELLOW "Test to Strdup() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}


void TestStrcat()
{
	int tests = 3;
	int pass = 0;
	char *src = "something";
	char *src1 = "";
	char *src2 = "abcdefd329942";
	char *src3 = "   abs   svjl 	sfl";
	
	char *dest1 = (char *)malloc(50);
	char *dest2 = (char *)malloc(50);
	memset(dest1, 0, 50);
	memset(dest2, 0, 50);

	if (!Strcmp(Strcat(dest1, src1), strcat(dest2, src1)))
	{
		++pass;
		free(dest1);
		free(dest2);
	}
	
	if (!Strcmp(Strcat(Strcpy(dest1, src), src2), strcat(Strcpy(dest2, src), src2)))
	{
		++pass;
		free(dest1);
		free(dest2);
	}
	
	if (!Strcmp(Strcat(Strcpy(dest1, src), src3), strcat(Strcpy(dest2, src), src3)))
	{
		++pass;
		free(dest1);
		free(dest2);
	}
	
	
	printf(YELLOW "Test to Strcat() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}

void TestStnrcat()
{
	int tests = 4;
	int pass = 0;
	char *src = "something";
	char *src1 = "";
	char *src2 = "abcdefd329942";
	char *src3 = "   abs   svjl 	sfl";
	
	char *dest1 = (char *)malloc(50);
	char *dest2 = (char *)malloc(50);
	memset(dest1, 0, 50);
	memset(dest2, 0, 50);

	if (!Strcmp(Strncat(dest1, src1, 5), strncat(dest2, src1, 5)))
	{
		++pass;
		free(dest1);
		free(dest2);
	}
	
	if (!Strcmp(Strncat(Strcpy(dest1, src), src2, 8), strncat(Strcpy(dest2, src), src2, 8)))
	{
		++pass;
		free(dest1);
		free(dest2);
	}
	
	if (!Strcmp(Strncat(Strcpy(dest1, src), src2, 20), strncat(Strcpy(dest2, src), src2, 20)))
	{
		++pass;
		free(dest1);
		free(dest2);
	}
	
	if (!Strcmp(Strncat(Strcpy(dest1, src), src3, 15), strncat(Strcpy(dest2, src), src3, 15)))
	{
		++pass;
		free(dest1);
		free(dest2);
	}
	
	
	printf(YELLOW "Test to Strncat() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}


void TestStrstr()
{
	int tests = 5;
	int pass = 0;
	char *needle = "abc";
	char *str = "something";
	char *str1 = "";
	char *str2 = "sfsabcdefd329942";
	char *str3 = "   abc   svjl 	sfl";
	char *str4 = "  what about abc ";
	
	if (Strstr(str, needle) == strstr(str, needle))
	{
		++pass;
	}
	
	if (Strstr(str1, needle) == strstr(str1, needle))
	{
		++pass;
	}
	
	if (Strstr(str2, needle) == strstr(str2, needle))
	{
		++pass;
	}

	if (Strstr(str3, needle) == strstr(str3, needle))
	{
		++pass;
	}
	
	if (Strstr(str4, needle) == strstr(str4, needle))
	{
		++pass;
	}

	printf(YELLOW "Test to Strstr() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
}


void TestStrspn()
{
	int tests = 8;
	int pass = 0;
	char *needle = "abc";
	char *needle1 = "abXXcdeZZh";
	char *needle2 = "";
	char *str = "something";
	char *str1 = "";
	char *str2 = "abcdef";
	char *str3 = "eabc";
	char *str4 = " abc";
	char *str5 = "abcdefgh";
	
	if (Strspn(str, needle) == strspn(str, needle))
	{
		++pass;
	}
	
	if (Strspn(str1, needle) == strspn(str1, needle))
	{
		++pass;
	}
	
	if (Strspn(str2, needle) == strspn(str2, needle))
	{
		++pass;
	}

	if (Strspn(str3, needle) == strspn(str3, needle))
	{
		++pass;
	}
	
	if (Strspn(str4, needle) == strspn(str4, needle))
	{
		++pass;
	}
	
	if (Strspn(str5, needle1) == strspn(str5, needle1))
	{
		++pass;
	}
	
	if (Strspn(str5, needle2) == strspn(str5, needle2))
	{
		++pass;
	}

	if (Strspn(str1, needle2) == strspn(str1, needle2))
	{
		++pass;
	}

	printf(YELLOW "Test to Strspn() --> "RESET "%s" "(%d,%d)\n"RESET, GetColor(tests,pass),tests,pass);
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
		case 1:
			TestStrlen();
			break;
		case 2:
			TestStrcmp();
			break;
		case 3:
			TestStrcpy();
			break;
		case 4:
			TestStrncpy();
			break;
		case 5:
			TestStrcasecmp();
			break;
		case 6:
			TestStrchr();
			break;
		case 7:
			TestStrdup();
			break;
		case 8:
			TestStrcat();
			break;
		case 9:
			TestStnrcat();
			break;
		case 10:
			TestStrstr();
			break;
		case 11:
			TestStrspn();
			break;
		default:
			TestStrlen();
			TestStrcmp();
			TestStrcpy();
			TestStrncpy();
			TestStrcasecmp();
			TestStrchr();
			TestStrdup();
			TestStrcat();
			TestStnrcat();
			TestStrstr();
			TestStrspn();
		}
	
	return 0;
}


