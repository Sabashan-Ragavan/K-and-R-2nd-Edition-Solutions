/* Write a binary seach function with only one test inside the loop and 
measure the difference in run-time */

/* *The binary search from the textbook proves to be faster* */
#include <stdio.h> 

int binSearch2(int x, int v[], int n); 
int binSearch1(int x, int v[], int n); 

int main()
{
	int array[] = {1, 2, 4, 6, 8, 9}; //test array (must be in ascending order) 
	printf("Results from binSearch2...\n"); 
	printf("%d\n", binSearch2(8, array, 6)); //should return 4
	printf("%d\n", binSearch2(4, array, 6)); //should return 2
	printf("%d\n\n", binSearch2(5, array, 6));	//should return -1 
	
	printf("Results from binSearch1...\n");
	//Should return same values as above...
	printf("%d\n", binSearch1(8, array, 6)); 
	printf("%d\n", binSearch1(4, array, 6)); 
	printf("%d\n", binSearch1(5, array, 6));	
	return 0; 
}

/* binary seach function which only makes only one test within the loop */
int binSearch2(int x, int v[], int n)
{
	int low = 0, high = n-1, mid; 
	mid = (low+high)>>1; 
	
	while(low <= high && v[mid] != x)
	{
		if(v[mid] < x)
			low = mid+1; 
		else
			high = mid-1; 
		mid = (low+high)>>1;
	}
	if(v[mid] == x)
		return mid; 
	else
		return -1; //not in array
}

/* binary search function from textbook */
int binSearch1(int x, int v[], int n)
{
	int low = 0, high = n-1, mid; 
	
	while(low <= high)
	{
		mid = (low+high)>>1; 
		if(v[mid] > x)
			high = mid -1 ;
		else if(v[mid] < x)
			low = mid +1; 
		else
			return mid; 
	}
	return -1; 
}
