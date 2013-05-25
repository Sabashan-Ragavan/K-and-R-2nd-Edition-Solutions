/* Write the function strrindex(s, t), which returns the position 
of the rightmost occurance of t in s, or -1 if there is none */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline1(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;
	int index; 

	while (getline1(line, MAXLINE) > 0)
	{
		if ((index = strrindex(line, pattern)) >= 0) 
		{
			printf("Line: %sIndex: %d\n", line, index); /*outputs the line with the pattern
								      and then the right most index */
			found++;
		}
	}
	return found;
}

/* getline: get line into s, return length */
int getline1(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strrindex: returns the position of the rightmost occurance of t in s or -1 if there is none */
int strrindex(char s[], char t[])
{
	int i, j, k, rightmostindex = -1;

	for (i = 0; s[i] != '\0'; i++) 
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0') 
		{
			if(i > rightmostindex)
				rightmostindex = i;
		}
	}
	return rightmostindex;
}

