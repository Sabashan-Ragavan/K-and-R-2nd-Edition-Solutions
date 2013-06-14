/* Write a pointer version of the funciton strcat that we showed in 
Chapter 2: strcat(s, t) copies the string t to the end of s */ 

#include <stdio.h> 

void strcatPointer(char *s, char *t); 
void strcatOriginal(char s[], char t[]); 

int main()
{
	char x[] = "Hello "; 
	char y[] = "World"; 
	strcatOriginal(x, y); 
	printf("%s\n", x); 

	char a[] = "Hello "; 
	char b[] = "World"; 
	strcatPointer(a, b); 
	printf("%s", a); 

	return 0; 
}

void strcatPointer(char *s, char *t)
{
	while(*s != '\0')
		s++; 
	while((*(s++) = *(t++)) != '\0')
		;
}

void strcatOriginal(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}
