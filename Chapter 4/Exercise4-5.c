/* Add access to library functions like sin, exp and pow. 
See <math.h> in Appendix B, Section 4. */ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> 

#define MAXOP 100
#define NUMBER '0'
#define WORD 'A' 
#define MAXVAL 100
#define BUFSIZE 100 

char buf[BUFSIZE]; 	
int bufp = 0; 
int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void print(void); 
void duplicate(void); 
void swap(void); 
void clear(void); 
void performMathFunction(char []); 

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF)
    {	
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
			case WORD: //reads that a word was inputed
				performMathFunction(s); //then if that word is a math function, performs it
				break; 
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
			case '%': 
				op2 = pop();
				if(op2 != 0.0)
					push(fmod(pop(), op2));  
				else
					printf("error: zero divisor\n"); 
				break; 
            case '\n':
				if(sp > 0) 
					printf("\t%.9g\n", val[sp-1]);
                else
					printf(""); 
				break;
			case '!' : //character to print top element (altered from last exercise)
				print(); 
				break;
			case '@' : //character to duplicate top element (altered from last exercise)
				duplicate(); 
				break ;
			case '#' : //character to swap top two elements (altered from last exercise)
				swap(); 
				break; 
			case '$' : //character to clear stack (altered from last exercise)
				clear(); 
				break; 
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
  
    return 0;
}

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cant push %g\n", f);  
	//printf("sp %d\n", sp);		
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c, next;
   
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
	
	i = 0; 
	if(isalpha(c))
	{
		while(isalpha(s[++i] = c = getch()));  
		s[i] = '\0'; 
		if(c != EOF)
			ungetch(c); 
		return WORD; 
	}
	
	if(!isdigit(c) && c != '.' && c != '-')
		return c; 
	
	if(c == '-')
	{
		next = getch(); 
		
		if(!isdigit(next) && next != '.')
			return c; 
			
		c = next;  		
	}
	else
	{
		c = getch(); 
	}
		
	while(isdigit(s[++i] = c))
		c = getch(); 
		
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();  
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n"); 
	else
		buf[bufp++] = c;  
 }

 /* function which prints top element in stack */ 
 void print(void)
 {
	//printf("sp %d\n", sp); 
	if(sp > 0)
		printf("Top Element: "); 	
	else
		printf("Stack Empty\n"); 
 }
 
/* function which duplicates top entry in stack */ 
void duplicate(void)
{
	//printf("sp %d\n", sp); 
	if(sp > 0 && sp < MAXVAL)
	{
		val[sp] = val[sp -1]; 
		sp++; 
		printf("Finished Duplicating Top Element: "); 
	}
	else if(sp >= MAXVAL && sp > 0)
		printf("Stack Full\n"); 
	else
		printf("Stack Empty\n"); 
}

/* function which swaps top two elements in stack */ 
void swap(void)
{
	if(sp > 1)
	{
		double tmp = val[sp - 1]; 
		val[sp -1] = val[sp-2]; 
		val[sp-2] = tmp; 
		printf("Finished Swapping. Top Element Now: "); 
	}
	else
		printf("Not enough elemnts to swap the top two elements\n"); 
}

/* function which clears the stack */ 
void clear(void)
{
	int i; 
	for(i = 0; i < sp; i++)
		val[i] = 0; 
	sp = 0; 
	printf("Finished Clearing: \n");
}

/* function which performs the appropriate math function */ 
void performMathFunction(char s[])
{
	//printf("%s\n", s) ; 
	double op2; 
	if(strcmp("sin", s) == 0)
		push(sin(pop())); 
	else if(strcmp("cos", s) == 0)
		push(cos(pop())); 
	else if(strcmp("exp", s) == 0)
		push(exp(pop())); 
	else if(strcmp("pow", s) == 0)
	{
		op2 = pop() ; 
		push(pow(pop(), op2)); 
	}
	else
		printf("%s is an undefined function", s); 
}
