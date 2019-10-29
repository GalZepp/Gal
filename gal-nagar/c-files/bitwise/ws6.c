#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/


/*Replacement to strrev*/
static char *strrev(char * string)
{
	if (string)
		{
		char *	left;
		char *	right;
		char	swap;

		left  = string;
		right = string + strlen(string) - sizeof(char);

		while (left < right)
			{
			swap	= *left;
			*left	= *right;
			*right	= swap;

			left++;
			right--;
			}
		}

	return(string);
}


static int AddBinNumbers(unsigned int x, unsigned int y)
{
    int carry = 0;
    
    while(0 != y)
    {
        carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

/*Multiplying x times 2 in the power of y*/
static long Pow2(unsigned int x, unsigned int y)
{
    return x << y;
}

/*Adding one to a number with bitwise operations*/
static long AddOneBin(unsigned int num)
{
    int carry = 1;

    while (num & carry)
    {
        num = num ^ carry;
        carry <<= 1;
    }
    
    num = num ^ carry;
    return num;
}

/*Checks if a number is a power of 2*/
static int IsPowOf2(unsigned int n)
{   
    if(n && !(n & (n - 1)))
    {
        return 1;
    }
    return 0;
}

/*Checks if a number is a power of 2*/
static int IsPowOf2Loop(unsigned int num)
{
    unsigned int tmp = 1;
    
    while (tmp < num)
    {
        tmp <<= 1;
        if (tmp == num)
        {
            return 1;
        }
    }
    
    return 0;
}

/*Counts if num has exactly 3 on bits*/
static int Are3BitsOn(unsigned int num)
{
	int count = 0;
	
	while ((0 != num) && (4 > count))
	{
		if (1 & num)
		{
			++count;
		}
		num >>= 1;
	}
	
	if (3 == count)
	{
		return 1;
	}
	return 0;
}

/*Receives an array and prints only the numbers with exactly 3 bits on*/
static void PrintNumsWith3BitOn(unsigned int num_arr[], int arr_length)
{
	int i = 0;
	
	while (arr_length > i)
	{
		if (Are3BitsOn(num_arr[i]))
		{
			printf("%d has 3 bits on\n", num_arr[i]);
		}
		++i;
	}
}

/*Mirrors the bits of a number*/
static unsigned int ByteMirrorWLoop(unsigned int num)
{
    int rev_num = num;
    int char_bit = 8;
    int shift_num = sizeof(num) * char_bit - 1;
    
    for (num >>= 1; num > 0; num >>= 1)
    {
    	rev_num <<= 1;
    	rev_num |= num & 1;
    	--shift_num;
    }
    
    return rev_num <<= shift_num;
}

/*Mirrors the bits of a number without a loop*/
static unsigned int ByteMirrorWithoutLoop(register int x)
{

	/* swap the bits: 0100 --> 1000 */
	x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));

	/* swap the 2 bits of a nibble: 10 00  --> 00 01 */
	x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));

	/* swaps the nibbles: 0011 0010 --> 0010 0011 */
	x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));

	/* swap the bytes of an integer */
	x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
	
	/*  swap the half-word of an integer */
	x = ((x >> 16) | (x << 16));
 
	return x;
}

/*Returns 1 if 2th and 6th bits are on*/
static int BothBits2And6AreOn(unsigned int num)
{
    int is_2_bit_on = 0;
    int is_6_bit_on = 0;
    
    is_2_bit_on = num & 2;
    is_6_bit_on = num & 32;
    
    return ((is_2_bit_on | 0) && (is_6_bit_on | 0));
}

/*Returns 1 if 2th or 6th bits are on*/
static int EitherBits2Or6AreOn(unsigned int num)
{
    int is_2_bit_on = 0;
    int is_6_bit_on = 0;
    
    is_2_bit_on = num & 2;
    is_6_bit_on = num & 32;
    
    return ((is_2_bit_on | 0) || (is_6_bit_on | 0));
}

/*Swaps between bit 3 and 5, and returns the new number*/
static int SwapBit3And5(unsigned int num)
{
    int pos_one = 3;
    int pos_two = 5;
    
    return num ^ ((1 << (pos_two - 1)) ^ (1 << (pos_one - 1)));
}


/*Subtract one with bitwise operation*/
static int SubtractOneBitwise(unsigned int num)
{
    int carry = 1;
    
    while (!(num & carry))
    {
        num = num ^ carry;
        carry <<= 1;
    }
    
    num = num ^ carry;
    
    return num;
}

/*Modulus operator with bitwise operations*/
static int NumberDividedBy16(unsigned int num)
{
    unsigned int carry = 0;
    
    carry = num & 15;
    
    while (0 != carry)
    {
        num = SubtractOneBitwise(num);
        carry = num & 15;
    }
    
    return num;
}

/*Swapping integer values*/
static void SwappingValuesBitwise(int num1, int num2)
{
    int *ptr_num1 = &num1;
    int *ptr_num2 = &num2;
    
    *ptr_num1 = *ptr_num1 ^ *ptr_num2;
    *ptr_num2 = *ptr_num1 ^ *ptr_num2;
    *ptr_num1 = *ptr_num1 ^ *ptr_num2;
}

/*Counts number of set bits with a loop*/
static int CountsSetBitsLoop(unsigned int num)
{
    int count = 0;
    
    while (num)
    {
        if (1 & num)
        {
            ++count;
        }
        num >>= 1;
    }
    
    return count;
}

/*Counts number of set bits with a recursive function*/
static int CountSetBitsRecursive(unsigned int num)
{
    if (0 == num)
    {
        return 0;
    }
    else
    {
        return (num & 1) + CountSetBitsRecursive(num >> 1);
    }
}

/*Count number of set bits without a loop*/
static int CountSetBitsNoLoop(int n) 
{ 
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n + (n >> 4)) & 0x0f0f0f0f;
    n = n + (n >> 8);
    n = n + (n >> 16);
    return n & 0x3f;  
}

/*Prints the bits of a float number*/
static void PrintBitsOfFloat(float num)
{
    char bits_arr[33];
	int i = 0;
    int *ptr = (int *)&num;
    
    while (32 > i)
    {
        if (1 & *ptr)
        {
            bits_arr[i] = '1';
        }
        else
        {
            bits_arr[i] = '0';
        }
        *ptr >>= 1;
        ++i;
    }
    
    bits_arr[i] = '\0';
    
    printf("%s\n", strrev(bits_arr));
}


int main ()
{
    printf("%u\n", ByteMirrorWLoop(2));
    printf("%u\n", ByteMirrorWithoutLoop(7));
    
    return 0;
}




































