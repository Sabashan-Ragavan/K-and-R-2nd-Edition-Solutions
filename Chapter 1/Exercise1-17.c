//Write a program to print all input lines longer than 80 characters

#include <stdio.h> 
#define MAXLINE 1000 
#define CUTOFF 80 /*Modify this value to whatever you want the 
				  cutoff for the amount of characters needed for it to be printed*/
 
int getline1(char s[]); 
 
int main()
{
	int len; 
	char line[MAXLINE]; 
	printf("This program will print all input lines greater than %d characters:\n", CUTOFF); 
	while((len = getline1(line)) > 0)
	{
		if(len > CUTOFF)
			printf("%s", line); 
		else 
			printf("Sorry %d characters that was not long enough\n", len); 
	}
	printf("\nDone with program\n"); 
	return 0; 
}

int getline1(char s[])
{
	int c; 
	int i = 0;  
	
	while((c = getchar()) != EOF && i < MAXLINE-1 && c != '\n')
	{
		s[i] = c; 
		i++; 
	}
	if(c == '\n')
	{
		s[i] = c; 
		i++; 
	}
	s[i] = '\0'; 
	return i; 
}


