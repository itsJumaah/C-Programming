#include<stdio.h>
int x, a;
int add2(int y, int z);
int main() {
	printf("enter a number: ");
	scanf("%d", &x);
	printf("enter a number: ");
	scanf("%d", &a);
	x = add2(x, a);
	printf("\nresult is %d", x);
}
int add2(int y, int z) {
	int result;
	result = x + y;
	return result;
}