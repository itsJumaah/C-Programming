#include <stdio.h>
int temp, time, hours, minutes, seconds;
int main() {
	printf("enter time in seconds: ");
	scanf("%d", &time);
	temp=time;
	hours=temp/3600;
	temp=temp-hours*3600;
	minutes=temp/60;
	temp=temp-minutes*60;
	seconds=temp;
	printf("%d seconds = %d hours, %d minutes, %d seconds",time,hours,minutes,seconds);
}