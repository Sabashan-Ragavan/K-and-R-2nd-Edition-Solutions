//Write a fucntion escape(s, t) that converts characters like 
//newline and tab into visible escape sequences like \n and \t 
//as it copies the string t to s, Use a switch. Write a function 
//for the other direction as well converting escape sequences 
//into real characters. 

#include <stdio.h> 
#define MAXLINE 1000 

void escape(char s[], char t[]); 
void unescape(char t[], char s[]);  

char s[MAXLINE] = ""; 
char t[MAXLINE] = "\nHappy\tBirthday\nHomie\bBye\n"; //test string 
 
int main()
{
	printf("Original: %s", t); 
	
	escape(s, t); 
	printf("Escaped: %s\n", s); 

	unescape(t, s); 
	printf("Unescaped: %s\n", t); 
	
	return 0; 
}

void escape(char s[], char t[])
{
	int i, j; 
	
	for(i=0, j=0; t[i] != '\0'; ++i, ++j)
	{
		switch(t[i])
		{
			//more escape characters can be added
			case '\t':
				s[j++] = '\\'; 
				s[j] = 't';
				break;				
			case '\n':
				s[j++] = '\\';
				s[j] = 'n'; 
				break; 
			case '\b':
				s[j++] = '\\';
				s[j] = 'b'; 
				break;
			default: 
				s[j] = t[i];
				break; 
		}
	}
	s[j] = t[i]; //add null character
}

void unescape(char t[], char s[])
{
	int i, j; 
	
	for(i=0, j=0; s[i] != '\0'; ++i, ++j)
	{
		if(s[i] == '\\')
		{  
			switch(s[++i])	
			{
				case 't':
					t[j] = '\t'; 
					break; 
				case 'n': 
					t[j] = '\n'; 
					break; 
				case 'b': 
					t[j] = '\b';
					break; 
				default:
					t[j++] = '\\';
					t[j] = s[i]; 	
					break; 
			}
		}
		else
		{
			t[j] = s[i]; 
		}
	}
	t[j] = s[i]; //add null character 
}


