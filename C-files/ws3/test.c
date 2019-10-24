#include <stdio.h>/* printf */
#include <string.h>/* strlen */

void foo(int a[], int size)
{
	int i = 0;

	for (i = 0; i < size; ++i)
	{
		a[i] = i * 2;
	}
	printf("sizeof(a) = %ld\n", sizeof(a));

}


int main ()
{
	char str[] = "welcome";
	int arr[10] = {0};
	foo(arr, 10);

	printf("sizeof(str) = %lu\n", sizeof(str));
	printf("strlen(str) = %lu\n", strlen(str));
	printf("sizeof(arr) = %lu\n", sizeof(arr));


	return 0;
}
