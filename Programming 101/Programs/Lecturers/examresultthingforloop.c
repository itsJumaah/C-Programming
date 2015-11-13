#include<stdio.h>
int count, zeromark;
float mark, total;
int main() {
	total=0.0;
	zeromark=0;
	for (count=0; count<8; count++) {
		printf("Enter mark for Question %d: ", count+1);
		scanf("%f", &mark);
		total=total+mark;
		if (mark==0.0) {
			zeromark++; //increment
		}
	}
	if (zeromark>=4){
		printf("You fail bitch!");
	}
	else {
		if (total<50) {
			printf("You fail bitch!");
		}
		else {
			printf("You passed ma nigga, and your final score is %1.0f%%", total);
		}
	}
}