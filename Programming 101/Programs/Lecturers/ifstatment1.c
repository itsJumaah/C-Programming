#include<stdio.h>
int bilal;
int main() {
	while(1<2){
	printf("Write a number and test your luck: ");
	scanf("%d", &bilal);
	if (bilal<0 && bilal > -10) {
		printf("You're cool!\n\n");
	}
	else if (bilal==0) {
	printf("You're an idiot >:)\n\n");
		}
		else {
			printf("You are \n\n");
		}
	}
}