/* Write a version of itoa that accepts three arguements instead of two. 
The third arguement is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make it wide enough */

#include <stdio.h> 

void itoa(int n, char s[], int width);  
void reverse (char s[]); 
int length(char s[]); 

int main()
{
	int x = 35; 
	char s[] = ""; 
	
	printf("%d\n", x); 
	itoa(x, s, 3); 
	printf("%s\n", s); //output should have one leading blank

	return 0;  
}

void itoa(int n, char s[], int width)
{
	int i, x, sign; 
	
	if((sign = n) < 0)
		n = -n; 
	i =0; 
	do
	{
		s[i++] = n % 10 + '0'; 
	}
	while((n/=10) > 0); 
	
	if(sign < 0)
		s[i++] = '-'; 
	
	if(width > i)
	{
		for(x = i; x < width; ++x)
			s[x] = ' '; 
		s[++x] = '\0'; 
	}	
	else
		s[i] = '\0'; 
	reverse(s); 
}

void reverse(char s[])
{
	int i =0, j = length(s) -1, x; 
	for( i = 0, j; i < j; ++i, --j)
	{
		x = s[i]; 
		s[i] = s[j]; 
		s[j] = x; 
	} 
}

int length(char s[])
{
	int i; 
	
	for(i =0; s[i] != '\0'; ++i)
		; 
	return i; 
}
