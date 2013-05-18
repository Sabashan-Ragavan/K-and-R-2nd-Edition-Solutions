//Modify the temperature conversion program to 
//print the table in reverse order, that is, from
//300 degrees to 0 (Fahrenheit to Celsius) 

#include <stdio.h> 

int main() 
{
	int fahr; 
	
	printf("%3s\t%6s\n", "Fahr", "Celsius"); 
	for(fahr = 300; fahr >= 0 ; fahr = fahr - 20)
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32)); 
		
	return 0;
}

