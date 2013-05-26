/* Write a function reverse that reverses the character string s. 
Use it to write a program that reverses its input a line at a time. */

#include <stdio.h> 
#define MAXLINE 1000 

int getline1(char s[]); 
void reverse(char s[], int length); 

int main()
{
	int len; 
	char line[MAXLINE]; 
	
	while((len = getline1(line)) > 0)
	{
		printf("Original: %s", line); 
		reverse(line, len); 
		printf("Reverse: %s", line); 
	}
	return 0; 
}

void reverse(char s[], int length)
{

	int i; 
	char x; 
	length = length -2; 
	for(i =0; i < (length)/2; i++)
	{
		x = s[i]; 
		s[i] = s[length-i]; 
		s[length-i] = x; 
	} 
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

