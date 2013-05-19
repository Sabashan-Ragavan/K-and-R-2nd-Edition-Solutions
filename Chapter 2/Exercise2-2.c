//Write a loop equivalent to the for loop above without using && or ||

#include <stdio.h> 
#define LIM 1000 //Change to whatever (as long as within range of int size)

int main()
{
	int i = 0, c; 
	int lim = LIM; 
	char s[LIM]; 
	
	while(i < lim-1)
	{
		if((c = getchar()) == '\n')
			break; 
		else if(c == EOF)
			break; 
		s[i] = c; 
		++i; 
	}
	s[i] = '\0'; 
	printf("Your input was: %s", s); 
	return 0; 
}
