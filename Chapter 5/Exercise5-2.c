/* As written, getint treats a + or - not followed by a digit as 
a valid representation of zero. Fix it to push such a character back
on the input */ 

/* admittedly looked up part of the solution as the question
was unclear to me */ 

#include <stdio.h> 
#include <ctype.h> 

int getch(void); 
void ungetch(int);
int getfloat(float *); 

int buf;	
int bufp = 0;

int main()
{ 
	float number;
	int	c;

	while ((c = getfloat(&number)) != 0 && c != EOF)
	{
		printf("%f\n", number);
	}

return 0;
	
	return 0; 
}

int getfloat(float *pn)
{
	int c, sign, power = 1; 
	
	while(isspace(c = getch()))
		;
	if(!isdigit(c) && c != '+' && c != '-')
	{
		ungetch(c); 
		return 0; 
	}
	sign = (c == '-') ? -1 : 1; 
	if(c == '+' || c == '-' )
		c = getch(); 
	if(isdigit(c))
	{
		for(*pn = 0; isdigit(c); c = getch())
			*pn = 10 * (*pn) + (c - '0'); 
		if(c == '.')
		{
			c = getch(); 
			for(; isdigit(c); c = getch())
			{
				*pn = 10 * (*pn) + (c - '0'); 
				power *= 10; 
			}	
		}	
	}
	else
	{
		ungetch(c); 
		return 0; 
	}	
	
	*pn = *pn/power; 
	*pn *= sign;
	if(c != EOF)
		ungetch(c); 
	return c; 
}

int getch(void)
{
	if (bufp > 0)
	{
		bufp = 0;
		return buf;
	}
	else
	{
		return getchar();
	}
}

void ungetch(int c)
{
	buf = c;
	bufp = 1;
}


