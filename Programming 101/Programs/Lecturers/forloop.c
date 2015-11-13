#include<stdio.h>
#include<math.h>
#include<windows.h>
float number, total, average, count;
int main() {
	system("color 1b");
	total=0.0;
	printf("Please enter as many numbers as you want to calculate the average and if you have finished type -1 at the end to show the result\n");
	for (count=0; count<10000; count++){
		printf("Enter a number: ");
		scanf("%f", &number);
		if(number == -1){
			break;
		}
		total=total+number;
	}
	average=total/count;
	printf("The average is %1.2f \n", average);
}