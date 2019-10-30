#include <stdio.h> /* printf */
#include <assert.h> /* assert */

#define INT_BITS ((sizeof(unsigned int) * 8))
#define BITS_IN_BYTE 8
#define BIT_5 16
#define BIT_3 4 

/******** Print Bits *****/
void PrintBits(unsigned int num)
{
	unsigned int last_bit = 1;
	unsigned int i = 1;
	last_bit <<= INT_BITS - 1;

	printf("num = %d\n\n", num);

	for (i = 1; (INT_BITS + 1) > i; ++i)
	{
		if (num & last_bit)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

		if (!(i % 8))
		{
			printf(" ");
		}

		last_bit >>= 1;
	}

	printf("\n\n");
}

/******  Power of 2 ******/
long Pow2(unsigned int x, unsigned int y)
{
	return x << y;
}

/******** Check of number divides by 2 *****/
int IsPowerOf2WLoop(unsigned int num)
{
	unsigned int reference = 1;

	while (reference < num)
	{
		reference <<= 1;

		if (reference == num)
		{
			return 1;
		}
	}

	return 0;
}

int IsPowerOf2WOLoop(unsigned int num)
{
	return ((num & (num - 1)) == 0) ? 1 : 0;
}

/********* Add 1 *******/
unsigned int AddOne(unsigned int num)
{
	unsigned int reference = 1;

	while (num & reference)
	{
		num ^= reference;
		reference <<= 1;
	}

	return num ^= reference;
}

/****** 3 bits are on ******/
int CountOnBits(unsigned int num)
{
	unsigned int reference = 1;
	int count = 0;
	unsigned int i = 0;

	for (i = 0; INT_BITS > i; ++i)
	{
		if (reference & num) 
		{
			++count;
		}
		reference <<= 1;
	}

	return count;
}

void Exactly3BitsOn(unsigned int arr[], int length)
{
	int arr_index = 0; 

	while (length > arr_index)
	{
		if (3 == CountOnBits(arr[arr_index]))
		{
			printf("%d\n", arr[arr_index]);
		}

		++arr_index;
	}
}

/******** Byte mirror with loop *****/
unsigned int ByteMirrorWLoop(unsigned int num)
{
	unsigned int new_num = 0;
	unsigned int i = 0;

	for (i = 0; (INT_BITS - 1) > i; ++i)
	{
		new_num ^= (num & 1);
		num >>= 1;
		new_num <<= 1;
	}

	return new_num ^= (num & 1);
}

/******** Byte mirror without loop *****/
unsigned int ByteMirrorWoLoop(unsigned int num)
{
	num = ((num & 0xaa) >> 1) | ((num & 0x55) << 1);

	num = ((num & 0xcc) >> 2) | ((num & 0x33) << 2);

	num = ((num & 0xf0) >> 4) | ((num & 0xf) << 4);

	return num;
}

/****** Check if both bit 2 and 6 are on *****/
unsigned int AreBothBits2And6On(unsigned int num)
{
	return (num & 32) && (num & 2);
}

/****** Check if both bit 2 and 6 are on *****/
unsigned int AreEitherBits2And6On(unsigned int num)
{
	return (num & 32) || (num & 2);
}

/******** Swaps bits 3 and 5 *****/
unsigned int SwapBits3And5(unsigned int num)
{
	if (BIT_3 & num)
	{
		if (!(BIT_5 & num))
		{
			num ^= BIT_3;
			num |= BIT_5;

			return num;
		}
	}
	
	if (BIT_5 & num)
	{
		if (!(BIT_3 & num))
		{
			num ^= BIT_5;
			num |= BIT_3;

			return num;
		}
	}

	return num;
}

/******* Closest smaller number divided by 16 *****/
unsigned int ClosestNumDividedBy16(unsigned int num)
{
	return num & 0xfffffff0;
}

/******** Swap number ********/
void SwapNums(unsigned int *num1, unsigned int *num2)
{
	*num1 ^= *num2;
	*num2 ^= *num1;
	*num1 ^= *num2;
}

/******** Count bits *******/
size_t CountBitsWLoop(int num)
{
	int reference = 1;
	unsigned int i = 0;
	size_t count = 0;

	for (i = 0; INT_BITS > i; ++i)
	{
		if (reference & num)
		{
			++count;
		}
		reference <<= 1;
	}

	return count;
}

unsigned int CountBitsRecursive(unsigned int num)
{
	if (!num)
	{
		return 0;
	}
	else
	{
		return (num & 1) + CountBitsRecursive(num >> 1);
	}
}

int main ()
{
	float num1 = 5.3; 
	int *ptr = (int *)&num1;
	unsigned int num2 = 5;
	unsigned int num3 = 10;

	PrintBits(*ptr);

	printf("%d\n", CountBitsRecursive(*ptr));

	SwapNums(&num2, &num3);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);
	
	
	return 0;
}
