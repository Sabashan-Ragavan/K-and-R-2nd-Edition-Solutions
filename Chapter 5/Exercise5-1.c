/* As written, getint treats a + or - not followed by a digit as 
a valid representation of zero. Fix it to push such a character back
on the input */ 

/* admittedly looked up part of the solution as the question
was unclear to me */ 

#include <stdio.h> 
#include <ctype.h> 

int getch(void); 
void ungetch(int);
int getint(int *); 

int buf;	
int bufp = 0;

int main()
{ 
	int number, c;

	while ((c = getint(&number)) != 0 && c != EOF)
	{
		printf("%d\n", number);
	}

	return 0; 
}

int getint(int *pn)
{
	int c, sign; 
	
	while(isspace(c = getch()))
		;
	if(!isdigit(c) && c != '+' && c != '-')
	{
		ungetch(c); 
		return 0; 
	}
	sign = (c == '-') ? -1 : 1; 
	if(c == '+' || c == '-')
		c = getch(); 
	if(isdigit(c))
	{
		for(*pn = 0; isdigit(c); c = getch())
			*pn = 10 * (*pn) + (c - '0'); 
	}
	else
	{
		ungetch(c); 
		return 0; 
	}
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


