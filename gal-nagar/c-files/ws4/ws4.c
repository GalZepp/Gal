#include <stdio.h> /*getchar, printf*/
#include <stdlib.h> /*system*/
#include <ctype.h> /*toupper*/
#include <assert.h> /*assert*/

typedef void(*ptr_table)(unsigned int);
#define ESC 27


/*prints A or T to the screen using if statement*/
int PrintAorTwithIf(void)
{   
    int check_sys;
    int input = 0;
    
    check_sys = system("stty -icanon -echo");
    
    if (-1 == check_sys)
    {
        return -1;
    }

    while(ESC != input)
    {
        input = getchar();
        
        if (input == 'a' || input == 'A')
        {
            printf("A pressed\n");
        }
        if (input == 't' || input == 'T')
        {
            printf("T pressed\n");
        }
    }
    
    check_sys = system("stty icanon echo");
    
    if (-1 == check_sys)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


/*prints A or T to the screen using switch statement*/
int PrintAorTwithSwitch(void)
{
    int check_sys;
    char input = 0;
    
    check_sys = system("stty -icanon -echo");
    
    input = getchar();
    
    if (-1 == check_sys)
    {
        return -1;
    }
    
    while(ESC != input)
    {
        switch (input)
        {
            case 'a': 
                printf("A pressed\n");
                break;
            case 'A': 
                printf("A pressed\n");
                break;
            case 't': 
                printf("T pressed\n");
                break;
            case 'T': 
                printf("T pressed\n");
                break;
            default: 
                printf("Not a valid character\n");
                break;
         }
         input = getchar();
     }
     
    check_sys = system("stty icanon echo");
     
     if (-1 == check_sys)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*print the ascii value of the number*/
void PrintChar(unsigned int input)
{
    printf("%c Pressed\n", toupper(input));
}

/*create lookup table*/
void CreateLUT(ptr_table *func_table)
{
    int i = 0;
    
    assert(func_table);
    
    
    for (i = 0; i < 256; ++i)
    {
        if (i == 'a' || i == 'A' || i == 't' || i == 'T')
        {
            func_table[i] = &PrintChar;
        }
        else
        {
            func_table[i] = NULL;
        }
    }
}


int main ()
{
    /*
    PrintAorTwithSwitch();
    PrintAorTwithIf();
    */
    int check_sys = 0;
    int input = 0;
    
    ptr_table func_table[256];
    
    check_sys = system("stty -icanon -echo");
    
    if (-1 == check_sys)
    {
        return -1;
    }
    
    CreateLUT(func_table);
    
    while (ESC != input)
    {
        input = getchar();
        
        if (func_table[input])
        {
            func_table[input](input);
        }
    }
    
    check_sys = system("stty icanon echo");
     
    if (-1 == check_sys)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    
    return 0;
}


