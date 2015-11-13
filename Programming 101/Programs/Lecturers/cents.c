#include<stdio.h>
#include<windows.h>
int cents;
int main() {
	system("color 1b");
	while(4>2){
		printf("Enter an amount less than 1 dollar: ");
		scanf("%d", &cents);
		if (cents >= 100){ /*dealing with errors that the user enters*/
			printf("\n%d is greater than one dollar\n", cents);
		}
		else if (cents % 10 != 0) {
			printf("\n%d does not end with zero\n", cents);
		}
		else { /*my whole program will be sitting here*/
			printf("%d cents = ", cents);
			if (cents >= 50) {
				cents=cents-50;
				printf("50 cents");
			}
			if (cents >= 20) {
				cents=cents-20;
				printf(" + 20 cents");
			}
			if (cents >= 20) {
				cents=cents-20;
				printf(" + 20 cents");
			}
			if (cents >= 10) {
				cents=cents-10;
				printf(" + 10 cents");
			}
		}
	}
}