#include<stdio.h>
int number, reverse, temp, digit;
int main() {
	printf("enter a number: ");
	scanf("%d", &number);
	temp=number;
	reverse=0;
	while (temp>0) {
		digit=temp%10;
		reverse=reverse*10+digit;
		temp=temp/10;
	}
	printf("The number is %d\n", number);
	printf("The reverse is %d", reverse);
}