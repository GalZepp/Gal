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

/******** Append lines to a file *******/
static status_t AppendToFile(const char str, const FILE *file_name)
{
	file_name = fopen("new_file", "a+");

	fgets(str, 100, stdin);
	while (*str != 27)
	{
		fputs(str, file_ptr);
		fgets(str, 100, stdin); 
	}

	fclose(file_ptr);


}
int main ()
{
	FILE *file_ptr = NULL;
	char str[100];

	file_ptr = fopen("new_file", "a+");

	fgets(str, 100, stdin);
	while (*str != 27)
	{
		fputs(str, file_ptr);
		fgets(str, 100, stdin); 
	}

	fclose(file_ptr);

	return 0;
}
