#include <stdio.h>
#include <stdlib.h>

int main_2()
{
	int x = 3, y = 2; //Bug - the variables need to be initialized => int x = 3, y = 2;
	int nums[6];
	int* arrPtr;

	// Section A - Print the variables
	puts("***** Section A *****");
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", x * y);

	// Section B - Print the static array "nums".
	puts("***** Section B *****");
	int i = 0;
	while (i < 6) 
	{
		nums[i] = i;  //Bug - you need to insert numbers into the array => nums[i] = i; 
		printf(" nums[%d] = %d\n", i, nums[i]);
		i++; //Bug - you need to advance I for the loop to move forward by 1 each time => i++
	}

	// Section C - Print allocated array.
	puts("***** Section C *****");
	arrPtr = (int*)malloc(sizeof(int) * 6); //Bug - there is no typecasting in the allocation => (int*), Bug2 - We were asked to assign 6 integer numbers in the dynamic array and no 10
	if (arrPtr) 
	{
		for (i = 0; i < 6; i++) 
		{
			arrPtr[i] = i;  //Bug - you need to insert numbers into the array => arrPtr[i] = i;
			printf("array[%d] = %d\n", i, arrPtr[i]);
			arrPtr++;  //Bug - you need to advance the allocated space in the memory (the pointer) to the next int => arrPtr++;
		}
	}
	else 
	{
		printf("Error Allocating Memory!\n");
		exit(1);
	}

	return 0;

} //Bug - There was no closing parenthesis } at the end of the function