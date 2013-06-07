/* Adapt the ideas of printd to write a recursive version of itoa; 
that is, convert an integer into a string by calling a recursive 
routine. */

#include <stdio.h> 

#define MAXLINE 10000 //maximum string length

char string[MAXLINE]; 
void recursiveitoa(int n); 

int main()
{	
	int x = -122; //test integer(change to whatver)
	recursiveitoa(x); 
	printf("%s", string); 
	return 0; 
}

/* recursive itoa function */
void recursiveitoa(int n)
{
	static int i = 0; 
	int sign; 
	
	if((sign = n) < 0) 
	{
		string[i++] = '-';
		n = -n; 
	}
	if(n/10)
		recursiveitoa(n/10); 
	string[i++] = n % 10 + '0'; 
	string[i] = '\0'; 
}

