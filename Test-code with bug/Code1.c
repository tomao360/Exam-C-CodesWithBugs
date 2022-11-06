#include <stdio.h> //Bug - Wasnt closed right: was <stdio.h<  => the right way: <stdio.h>
#pragma warning(disable : 4996) //Bug - you need to include #pragma warning(disable : 4996)    

 int main_1() 
 {
	int a = 4, b = 7;  //Bug - there is a ;  when you define more than one variable in the same line, you need to seperate them with ,
	float c;
	scanf("%f", &c); //Bug - in scanf you need to write & before the variable
	if (c == 5)   //Bug - you need to write with lvalue and you need to write ==, because only one = is a placment of a variable => c == 5 an
	printf("%f", c);  //Bug - the rught way to write printf is with f at the end

	return 0;  //Bug - you need to return 0 at the end of the main to know if the program finushed successfully
}