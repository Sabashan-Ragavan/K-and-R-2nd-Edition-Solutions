//Write a program to print a histogram of the lengths of words in its input 

#include <stdio.h> 
#define MAXWORDS 100 //set to whatever you want the maximum number of words to be

int main()
{
	int c, n, i = 0, j = 0; 
	int state = 0; //if state = 0 then not in word else in a word
	int nletters[MAXWORDS]; 
	
	for(n = 0; n < MAXWORDS; ++n)
		nletters[n] = 0; 
	
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c== '\n')
		{
			if(state == 1)
				i++; 
			state = 0 ;
		}
		else
		{
			++nletters[i]; 	
			state = 1; 
		}			
	}
	
	for(n = 0; n < i; ++n)
	{
		printf("Word %d = ", n+1); 	
		for(j = 0; j < nletters[n]; ++j)
			printf("-"); 
		printf("\n"); 
	}
	return 0; 
}
