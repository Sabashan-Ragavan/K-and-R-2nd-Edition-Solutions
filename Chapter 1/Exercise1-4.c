/* Write a program to print the coreesponding Celsius to Fahrenheit table */ 

#include <stdio.h> 

int main() 
{
	float fahr, celsius; 
	int lower, upper, step; 
	
	lower = 0; 
	upper = 300; 
	step = 20; 
	
	printf("%3s\t%6s\n", "Celsius", "Fahr");
	celsius = lower; 
	while(celsius <= upper)
	{
		fahr = (9.0/5.0)*celsius + 32.0; 
		printf("%3.0f\t%6.1f\n", celsius, fahr); 
		celsius = celsius + step; 
	}
	
	return 0; 
}

