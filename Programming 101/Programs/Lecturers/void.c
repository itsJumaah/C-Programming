#include<stdio.h>
void prompt (int min, int max);
int a, b;
int main() {
	prompt(12, 48);
	scanf("%d", &a);
	prompt(85, 102);
	scanf("%d", &b);
}
void prompt(int min, int max){
	printf("Enter a number\n");
	printf("the number must be from %d to %d\n", min, max);
	printf("press enter after the number:\n");
}