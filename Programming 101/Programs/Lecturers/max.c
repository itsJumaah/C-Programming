#include<stdio.h>
int a, b, c, max;
int main() {
	printf("Type in 3 numbers");
	scanf("%d %d %d", &a, &b, &c);
	max=a;
	if (max < b) {
		max=b;
	}
	if (max < c ) {
		max=c;
	}
	printf("The max is %d", max);
}
