#include <stdio.h> 

int htoi(char s[]); 
int power(int base, int n); 

int main()
{
	char test[] = "0xABC";  //can alter to what ever you like
	printf("%d\n", htoi(test)); 
	return 0; 
}

int htoi(char s[])
{ 
	int len = length(s);  	
	int i, n, intvalue = 0;
	
	for(i = len-1, n = 0; ; --i, ++n)
	{
		if(s[i] >= '0' && s[i] <= '9')
			intvalue += power(16, n)*(s[i] - '0') ; 
		else if(s[i] >= 'A' && s[i] <= 'F') 
			intvalue += power(16, n)*(s[i] - 'A' + 10) ;
		else if(s[i] >= 'a' && s[i] <= 'f')
			intvalue += power(16,n)*(s[i] - 'a' + 10); 
		else if((s[i] == 'x' || s[i] == 'X') && s[i-1] == '0')
			return intvalue; 
		else if(intvalue != 0)
			break; 
		else 
			return -1; //return a -1 if invalid hexadecimal string
	}
	return intvalue; 
}

int length(char s[])
{
	int i = 0; 
	while(s[i] != '\0')
		++i; 
	return i; 
}

int power(int base, int n)
{
	int i; 
	int total = 1; 
	for(i =0; i < n; i++)
	{
		total = base*total; 
	}
	return total;
}
