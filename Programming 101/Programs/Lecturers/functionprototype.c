#include<stdio.h>
void prompt(int max);
int a, b;
int main() {
	prompt(44);
	scanf("%d", &a);
	prompt(69);
	scanf("%d", &b);
}
void prompt (int max) {
	printf("Please type in a number\n");
	printf("The number must be from 0 to %d\n", max);
	printf("Press Enter after the number");
}