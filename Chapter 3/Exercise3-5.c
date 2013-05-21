#include <stdio.h> 

void itob(int n, char s[], int b); 
void reverse (char s[]); 
int length(char s[]); 

int main()
{
	int x = 985; //test value
	char s[] = ""; 
	char t[] = ""; 
	char u[] = ""; 
	
	printf("Test Value as Integer: %d\n", x);  
	itob(x, u, 16); 
	printf("Test Value as Character String Base 16: %s\n", u); //should output 3D9
	
	return 0;  
}

void itob(int n, char s[], int b)
{
	int i, x, sign; 
	
	if((sign = n) < 0)
		n = -n; 
	i = 0; 
	do
	{ 
		x = n%b; 
		if(x < 10)
			//printf("$d", x); 
			s[i++] = x + '0'; 
		else
			s[i++] = (x - 10) + 'A'; 
	}
	while((n /= b) > 0); 
	
	if(sign < 0)
		s[i++] = '-'; 
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
