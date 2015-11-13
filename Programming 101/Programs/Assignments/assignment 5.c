//Program written by Andrew Burden (12194226)
//This program calculates statistical combinations in the form n! / ((n-r)! * r!)

#include <stdio.h>

int factorial(int input); //Function prototype

int n, r, result;

int main()
{
	while(true) //Get n from the user
	{
		printf("Enter n, which must be a whole number less than 13 and greater than 0: ");
		scanf("%d", &n);
		if((n < 1) || (n > 12))
		{
			printf("You entered a number outside the range.\n");
			continue;
		}
	break;
	}
while(true) //Get r from the user
	{
		printf("Enter r, which must be a whole number less than n and greater than 0: ");
		scanf("%d", &r);
		if((r < 1) || (r > n))
		{
			printf("You entered a number outside the range.\n");
			continue;
		}
	break;
	}

result = factorial(n) / (factorial(n - r) * factorial(r)); //Calculates the combination
printf("The result is %d.", result);	
}

int factorial(int input) //Function definition
{
	//This function returns the factorial of the argument, e.g. factorial(4) = 4 x 3 x 2 x 1 = 24
	int newNum;
	newNum = input;
	while(input > 1)
		{
			input--;
			newNum = newNum * input;
		}
	return newNum;
}