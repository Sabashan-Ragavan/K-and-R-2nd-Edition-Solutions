/* Extend atof to handle scientific notation of the form 123.45e-6 
where a floating point number may be followed by e or E and an optionally 
signed exponent */

#include <stdio.h> 
#include <ctype.h>
#define MAXLINE 100

double atof(char s[]); 
int getline1( char line[], int max); 

int main()
{
	double sum; 
	char line[MAXLINE]; 
	
	sum = 0.0; 
	while(getline1(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line)); 
	return 0; 
}

/* extended atof which includes scientific notation */ 
double atof(char s[]) 
{
	double val, power, exp; 
	int i, sign, expsign; 
	
	for(i =0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1; 
	if(s[i] == '-' || s[i] == '+')
		i++; 
	for(val =0.0; isdigit(s[i]); i++)
		val = 10.0*val + (s[i] - '0'); 
	if(s[i] == '.')
	{
		i++; 
		for(power = 1.0; isdigit(s[i]); i++)
		{
			val = 10.0*val + (s[i] - '0'); 
			power *= 10.0; 
		}
	}
	if(s[i] == 'e' || s[i] == 'E' )
	{
		i++; 
		expsign = (s[i] == '-') ? -1 : 1;  
		if(s[i] == '-' || s[i] == '+')
			i++; 	
		for(exp =0.0; isdigit(s[i]); i++)
			exp = 10.0*exp + (s[i] - '0'); 	
		if(expsign == -1)
			return (sign*val*pow(10, -exp))/power;
		else			
			return (sign*val*pow(10, exp))/power; 
	}
	else
	{
		power = 1; 
	}
	return (sign*val)/power; 
}

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

