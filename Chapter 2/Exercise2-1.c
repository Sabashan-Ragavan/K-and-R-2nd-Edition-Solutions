/* Write a program to determine the ranges of char, short, int, and long variables
both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of 
the various floating-point types. */

#include <stdio.h> 
#include <limits.h> 
#include <float.h> 

int main()
{
	printf("Max Signed char: %d, Min Signed char %d\n", SCHAR_MAX, SCHAR_MIN); 
	printf("Max Unsigned char: %u\n\n", UCHAR_MAX); 
	
	printf("Max Signed short: %d, Min Signed short %d\n", SHRT_MAX, SHRT_MIN); 
	printf("Max Unsigned short: %u\n\n", USHRT_MAX); 
	
	printf("Max Signed int: %d, Min Signed int %d\n", INT_MAX, INT_MIN); 
	printf("Max Unsigned int: %u\n\n", UINT_MAX);
	
	printf("Max Signed long: %ld, Min Signed long %ld\n", LONG_MAX, LONG_MIN); 
	printf("Max Unsigned long: %lu\n\n", ULONG_MAX); 
	
	printf("Max float: %e, Min float: %e\n\n", FLT_MAX, FLT_MIN); 
	
	printf("Max double: %e, Min double: %e\n\n", DBL_MAX, DBL_MIN); 
	
	printf("Max long double: %e. Min long double: %e\n", LDBL_MAX, LDBL_MIN); 
	
	return 0; 
}
