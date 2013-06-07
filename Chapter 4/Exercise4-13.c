/* Write a recursive version of the function reverse(s), 
which reverses the string s in place. */ 

#include <stdio.h> 

#define MAXLINE 1000 

void reverse(char s[], int j); 
int length(char s[]); 

int main()
{
	char s[MAXLINE] = "Hello World"; //test string(change to whatever)
	reverse(s, length(s)-1); 
	printf("%s", s); //test string should be reversed
	return 0; 
}

/* function to recursively reverse string */ 
void reverse(char s[], int j)
{
	static int i = 0; 
	int tmp;
	if(i > j) //base case 
		return; 
	tmp = s[i]; 
	s[i] = s[j]; 
	s[j] = tmp; 
	i++; 
	reverse(s, --j); 
}

/* funciton to get the length of the string */ 
int length(char s[])
{
	int i; 
	for(i = 0; s[i] != '\0'; ++i)
		;
	return i; 
}
