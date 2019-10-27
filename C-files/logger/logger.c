#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <string.h> /* strcmp */

typedef enum status
{
	SUCCESS,
	FAIL,
	EXIT
} status_t;

typedef struct Operations
{
	char *oper_name;
	int (*compare_func_t)(const char *str1, const char *str2);
	status_t (*action_func_t)(const char str, const FILE *file_name);
} operation_t;


