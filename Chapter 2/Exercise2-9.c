/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount */

#include <stdio.h> 

int fasterBitCount(unsigned x); 

int main()
{
	int test = 7; //Change to whatver number you like
	printf("%d\n", fasterBitCount(test)); //Should output 3 for the current test number
	return 0; 
}

int fasterBitCount(unsigned x)
{
	int i = 0; 
	
	while(x != 0)
	{
		i++; 
		x &= (x-1);
	}
	return i; 
}
