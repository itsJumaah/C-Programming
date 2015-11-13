#include<stdio.h>
int max, number; /*unkown number of values*/
int main() {
	max=-999;
	while (true){
		printf("enter a number (-1 to stop)");
		scanf("%d", &number);
		if (number==-1){
			break;
		}
		if(max<number){
			max= number;
		}
	}
	printf("the largest number is %d", max);
}