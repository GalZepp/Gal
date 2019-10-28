#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <string.h> /* strcmp */
#include <stdlib.h> /* exit */

#define INPUT_STRING_SIZE 100
#define NUM_OF_OPER 3 

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
	status_t (*action_func_t)(const char *str, const char *file_name);
} operation_t;

/******** Check for fopen/fclose failure *********/
static status_t CheckFilePtr(FILE *file_ptr)
{
	if (!file_ptr)
	{
		return FAIL;
	}

	return SUCCESS;
}

/******** Append lines to a file *******/
static status_t AppendToFile(const char *str, const char *file_name)
{
	FILE *file_ptr = NULL;
	
	file_ptr = fopen(file_name, "a+");
	if (FAIL == CheckFilePtr(file_ptr))
	{
		return FAIL;
	}

	fputs(str, file_ptr);

	fclose(file_ptr);

	return CheckFilePtr(file_ptr);
}

/********* Exit file *********/
static status_t ExitFile(const char *str, const char *file_name)
{
	assert(str);
	assert(file_name);

	if (str){};
	if (file_name){};

	exit(1);
}

/*********** Remove file **********/
static status_t RemoveFile(const char *str, const char *file_name)
{
	assert(str);
	assert(file_name);

	if (str){};

	if (!remove(file_name))
	{
		printf("File was deleted\n");

		return SUCCESS;
	}

	printf("Unable to delete file\n");
	
	return FAIL;
}

/********* Count Lines ******/
static status_t CountLines(const char *str, const char *file_name)
{
	FILE *file_ptr = NULL;
	size_t count = 0;
	int ch = 0;

	assert(str);
	assert(file_name);

	if (str){};

	file_ptr = fopen(file_name, "r");
	if (FAIL == CheckFilePtr(file_ptr))
	{
		return FAIL;
	}
	
	ch = fgetc(file_ptr);

	while (EOF != ch)
	{
		if ('\n' == ch)
		{
			++count;
		}

		ch = fgetc(file_ptr);
	}

	printf("%s has %lu lines\n", file_name, count);

	fclose(file_ptr);

	return CheckFilePtr(file_ptr);
}

/******** Run Log **********/
status_t RunLog(char *file_name, operation_t *opt_arr)
{
	char user_input[INPUT_STRING_SIZE];
	size_t exit = 1;
	int append = 1;
	int is_diff = 0;
	size_t oper_index = 0;
	
	printf("Write to file: \n");

	while (exit != oper_index)
	{
		if (!fgets(user_input, INPUT_STRING_SIZE, stdin))
		{
			return FAIL;
		}
		
		for (oper_index = 0; NUM_OF_OPER > oper_index; ++oper_index)
		{

			is_diff = opt_arr[oper_index].compare_func_t(user_input, opt_arr[oper_index].oper_name);

			if (!is_diff)
			{
				opt_arr[oper_index].action_func_t(user_input, file_name);
				append = 0;
				break;
			}
		}	

		if (append)
		{
			if (AppendToFile(user_input, file_name))
			{
				return FAIL;
			}
		}

		append = 1;
	}	

	return SUCCESS;
}


/********* Initializing struct array *******/
void InitStructArray(operation_t opt_arr[])
{
	/**** Init for RemoveFile *****/
	opt_arr[0].oper_name = "-remove\n";
	opt_arr[0].compare_func_t = strcmp;
	opt_arr[0].action_func_t = RemoveFile;

	/***** Init for ExitFile *****/
	opt_arr[1].oper_name = "-exit\n";
	opt_arr[1].compare_func_t = strcmp;
	opt_arr[1].action_func_t = ExitFile;

	/**** Init for CountLines *****/
	opt_arr[2].oper_name = "-count\n";
	opt_arr[2].compare_func_t = strcmp;
	opt_arr[2].action_func_t = CountLines;
	
}


int main (int argc, char **argv)
{
	char *file_name = NULL;
	operation_t opt_arr[NUM_OF_OPER];
	status_t run_status = SUCCESS;
	
	InitStructArray(opt_arr);

	if (1 < argc)
	{
		file_name = argv[1];
		run_status = RunLog(file_name, opt_arr);

		if (run_status == FAIL)
		{
			printf("Program has failed\n");
		}
	}
	else
	{
		printf("No file name has been entered\n");
	}

	
	return 0;
}
	
