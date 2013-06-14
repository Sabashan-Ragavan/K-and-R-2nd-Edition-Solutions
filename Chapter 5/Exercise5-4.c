#include <stdio.h> 

#define true 1 
#define false 0 

int strend(char *s, char *t); 
int length(char *s); 

int main()
{
	char x[] = "World Hello"; 
	char y[] = "ello"; 
	
	int result1 = strend(x, y); 
	printf("Should return 1:\n%d\n", result1); 
	
	char a[] = "Hello World"; 
	char b[] = "ello"; 
	
	int result2 = strend(a, b); 
	printf("Should return 0:\n%d\n", result2); 
	
	return 0; 
}

int strend(char *s, char *t)
{
	int len1 = length(s); 
	int len2 = length(t); 
	//printf("%d %d\n", len1, len2); 
	while(true)
	{
		//printf("%c %c\n", *(s+len1-1), *(t+len2-1));
		if(!(*(s+len1-1) == *(t+len2-1)))
			return false; 
		--len1; 
		--len2; 
		if(len2 == 0 || len1 == 0)
			break; 
	}
	return true; 
	
}

int length(char *s)
{
	int i = 0; 
	for( ; *s != '\0'; s++)
		i++; 
	return i; 
}
