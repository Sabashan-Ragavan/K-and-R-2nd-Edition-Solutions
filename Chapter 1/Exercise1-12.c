//Write a program that prints its input one word per line

#include <stdio.h> 

int trim(); 

int main()
{
	int c; 
 	
	while((c=getchar()) != EOF)
	{
		if(c == '\n' || c == '\t' || c == ' ')
		{			
			printf("\n"); 
			if(trim() == 0)
				break; 
		}
		else
		{
			putchar(c); 
		}
	}
	return 0; 
}

int trim()
{
	int c = getchar(); 
	if(c == EOF)
		return 0; 
	while(c == '\n' || c == '\t' || c == ' ') 
	{
		c = getchar(); 
		if(c == EOF)
			return 0; 
	}
	putchar(c); 
	return 1; 
}



