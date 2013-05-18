//Write a program to count blanks, tabs, and newlines

#include <stdio.h> 

int main()
{
	int numblanks = 0, numtabs = 0, numnewlines = 0; 
	int c;
	while((c = getchar()) != EOF)
	{ 
		if(c == ' ')
			++numblanks;
		if(c == '\t')
			++numtabs; 
		if(c == '\n')
			++numnewlines; 
	} 
	
	printf("\nBlanks = %d Tabs = %d Newlines = %d\n", numblanks, numtabs, numnewlines); 
	
	return 0; 
}

