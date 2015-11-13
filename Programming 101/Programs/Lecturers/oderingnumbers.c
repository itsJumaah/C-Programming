#include<stdio.h>
int num1, num2, num3;
int main(){
	while(1==1){
	printf("type in 3 numbers that you want to display in the write order: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	if (( num1 < num2 ) && ( num1 < num3 )) {
		printf("%d ", num1);
		if ( num2 < num3 ) {
			printf("%d %d\n", num2, num3);
		}
		else {
			printf("%d %d\n", num3, num2);
		}
	}
	if (( num2 < num1 ) && ( num2 < num3 )) {
		printf("%d ", num2);
		if ( num1 < num3 ) {
			printf("%d %d\n", num1, num3);
		}
		else {
			printf("%d %d\n", num3, num1);
		}
	}
	if (( num3 < num1 ) && ( num3 < num2 )) {
			printf("%d ", num3);
		if ( num1 < num2 ) {
			printf("%d %d\n", num1, num2);
		}
		else {
			printf("%d %d\n", num2, num1);
		}
	}
}
}