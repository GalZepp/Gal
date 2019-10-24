#include <stdio.h> /*printf*/
#include <string.h> /*strdup*/
#include <stdlib.h> /*malloc*/
#include <ctype.h> /*tolower*/
#include <assert.h> /*assert*/

/*char *strdup(char *src);*/


/*Find the length of an array*/
int FindPptrLength(char **str)
{
	char **tmp = str;
	int counter = 0;
	
	assert(str);
	
	while (*tmp)
	{
		++counter;
		++tmp;
	}
	
	return counter;
}

/*Duplicate the content of array to ptr*/
void CopyArrToPptr(char **dest, char **src)
{
	char **d_tmp = dest;
	char **s_tmp = src;
	
	assert(src);
	assert(dest);
	
	while (*s_tmp)
	{
	    *d_tmp = strdup(*s_tmp);
        ++s_tmp;
        ++d_tmp;
	}
}


/*Loops over strings and converts letters to to lower case*/
void ChangeStrToLower(char **src)
{
    char **tmp = src;
    int go_back = 0;
    
    assert(src);
    
    while (*tmp)
    {
        go_back = 0;
        while (**tmp)
        {
            **tmp = tolower(**tmp);
            ++(*tmp);
            --go_back;
        }
        *tmp += go_back;
        ++tmp;
    }
}

void PrintArrContent(char **str)
{
    char **tmp = str;
    
    assert(str);
    
    while (*tmp)
    {
        printf("%s\n", *tmp);
        free(*tmp);
        ++tmp;
    }
}

int Josephus(int n)
{
	int j = 0, i = 0;;
	int arr[n];
	int alive = n;
	
	
	
	while (j < n) /*create array of zeros*/
	{
	    arr[j] = 0;
	    ++j;
	}
	
	if (n = 0)
	{
	    return 0;
	}
	
	while (alive > 1)
	{
	    i = i % n;
	    if (arr[i] == 0) /*check if alive*/
	    {
	        while (arr[(i + 1) % n] == 1) /*check if next is dead*/
	        {
	            ++i;
	        }
	        arr[(i+1) % n] = 1; /*kills next alive*/
	        --alive;
	    }
	    i++;
	}
	
	i = 0;
	while (arr[i] != 0) /*find i - the one left alive*/
	{
	    ++i;
	}
	return i + 1;
}

int main (int argc, char **argv, char **envp)
{
	/*
	int pptr_length = FindPptrLength(envp);
	char **buffer = NULL;
	
	buffer = (char **)malloc(sizeof(char *) * (pptr_length + 1));
	
    CopyArrToPptr(buffer, envp);
    
    ChangeStrToLower(buffer);
    
    PrintArrContent(buffer);
	
	free(buffer);
	buffer = NULL;
	*/
	printf("%d", Josephus(100));
	
	
	
	return 0;
}









































