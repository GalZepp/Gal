#include <stdio.h> /*prinf, remove, fgets, fgetc, fputc*/
#include <stdlib.h>/*exit*/
#include <string.h> /*strcmp*/
#include <assert.h>/*assert*/

#define STRING_INPUT_SIZE 100

int strcmp(const char *str1, const char *str2);

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
}operation_t;

/*removes file*/
static status_t RemoveFile(const char *str, const char *file_name)
{
    assert(str);
    assert(file_name);
    
    if(str){};
    
    if (remove(file_name) == 0)
    {
    	printf("File deleted\n");
    }
    else
    {
    	printf("Unable to delete\n");
    	return FAIL;
    }
    
    return SUCCESS;
}

/*Appending text to file*/
static status_t AppendLineToEndFile(const char *str, const char *file_name)
{
    FILE *ptr_file = NULL;
    
    assert(file_name);
    assert(str);
    
    ptr_file = fopen(file_name, "a+");
    
    if (NULL == ptr_file)
    {
        return FAIL;
    }
    
    fputs(str,ptr_file);
    if (0 != fclose(ptr_file))
    {
        return FAIL;
    }
    return SUCCESS;
}


/*counting the lines of the file*/
static status_t CountLinesInFile(const char *str, const char *file_name)
{
    FILE *file_ptr;
    int count = 0;
    char ch;
    
    assert(str);
    assert(file_name);
    
    file_ptr = fopen(file_name, "r");
    
    if(str){};
    
    if (file_ptr == NULL)
    {
        printf("could not find file %s\n", file_name);
        return FAIL;
    }
    
    while (ch != EOF) 
    {
        ch = getc(file_ptr);
        if (ch == '\n')
        {
            ++count;
        }
    }
    
    if (0 != fclose(file_ptr))
    {
        return FAIL;
    }
    printf("The file %s has %d lines\n", file_name, count);
    
    return SUCCESS;
}

static status_t WriteInFirstLine(const char *str, const char *file_name)
{
    char ch = 0;
    FILE *ptr_file = NULL;
    FILE *ptr_tmp = NULL;

    assert(str);
    assert(file_name);
    
    ptr_tmp = fopen("tmp_file", "a");
    
    if (NULL == ptr_tmp)
    {
        printf("ptr_tmp = %s", file_name);
        return FAIL;
    }
    
    ++str;
    if (EOF == fputs(str, ptr_tmp))
    {
        return FAIL;
    }
    
    ptr_file = fopen(file_name, "r");
    
    if (NULL == ptr_file)
    {
        printf("ptr_file = %s\n", file_name);
        return FAIL;
    }
    
    ch = fgetc(ptr_file);
    while (EOF != ch)
    {
       if (EOF == putc(ch, ptr_tmp))
        {
            return FAIL;
        }
       ch = fgetc(ptr_file);
    }
    
    if ((0 != fclose(ptr_tmp)) && (0 != fclose(ptr_file)))
    {
        return FAIL;
    }
    
    if (-1 == remove(file_name))
    {
        return FAIL;
    }  
    if (-1 == rename("tmp_file", file_name))
    {
        return FAIL;
    }
   
    return 0;
}

static status_t ExitFile(const char *str, const char *file_name)
{
    assert(str);
    assert(file_name);
    
    if(str){};
    if(file_name){};
	   
    exit(1);
}

/*Run Log*/
status_t RunLog(char *file_name, operation_t *opt_arr)
{
    char user_input[STRING_INPUT_SIZE];    
    int oper_index = 0;
    status_t is_strs_equal = SUCCESS;
    int header_flag = 0;
    FILE *ptr = fopen(file_name, "a+");
    fclose(ptr);
    
    printf("Write to file: \n");
     
    while (0 != strcmp(user_input, "-exit"))
    {	
    	if (NULL == fgets(user_input , STRING_INPUT_SIZE, stdin))
    	{
    	    return FAIL;
    	}
    	
    	if ('<' == user_input[0])
    	{
    	   WriteInFirstLine(user_input, file_name);
    	   header_flag = 1;
    	}
    	
    	while (3 > oper_index)
    	{
    		is_strs_equal = opt_arr[oper_index].compare_func_t(opt_arr[oper_index].oper_name, user_input);
    		
    		if (!is_strs_equal)
    		{
    			header_flag = 1;
    			opt_arr[oper_index].action_func_t(user_input, file_name);
    			break;
    		}
    		++oper_index;
    	}
    	if (0 == header_flag)
    	{
    	    if(0 != AppendLineToEndFile(user_input, file_name))
            {
    	        return FAIL;
    	    }
    	}
    	header_flag = 0;
    	oper_index = 0;
    }
    return SUCCESS;
}

/*initializing struct array*/
void InitStructArray(operation_t opt_arr[])
{
    /*init CountLinesInFile*/
    opt_arr[0].oper_name = "-count\n";
    opt_arr[0].compare_func_t = strcmp;
    opt_arr[0].action_func_t = CountLinesInFile;
    
    /*init RemoveFile*/
    opt_arr[1].oper_name = "-remove\n";
    opt_arr[1].compare_func_t = strcmp;
    opt_arr[1].action_func_t = RemoveFile;
    
    /*init ExitFile*/
    opt_arr[2].oper_name = "-exit\n";
    opt_arr[2].compare_func_t = strcmp;
    opt_arr[2].action_func_t = ExitFile;
}

int main (int argc, char **argv)
{
    char *file_name = NULL;
    status_t Run_status = SUCCESS;
    operation_t opt_arr[3];
    InitStructArray(opt_arr);
    
    if (argc == 1)
    {
        printf("No file name has been entered\n");
        return FAIL;
    }
    file_name = argv[1];
    
    Run_status = RunLog(file_name, opt_arr);
    
    if (FAIL == Run_status)
    {
        printf("Program Failed\n");
    }
    
    return 0;
}

