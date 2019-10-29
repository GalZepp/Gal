#include <stdio.h> /* printf */
#include <assert.h> /* assert */

#define INT_BITS ((sizeof(unsigned int) * 8))
#define BITS_IN_BYTE 8

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


int main ()
{
	unsigned int num = 8; 

	PrintBits(AreEitherBits2And6On(num));
	
	return 0;
}
