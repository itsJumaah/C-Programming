#include<stdio.h>
int day, year, month, max;
int maxdays(int m, int y);
int febdays(int yr);
int main() {
	printf("Enter a date, eg. 13/2/2012: ");
	scanf("%d/%d/%d", &day, &month, &year);
	day++;
	max=maxdays(month, year);
	if (day>max) {
		day=1;
		month++;
	}
	if (month==13) {
		month=1;
		year++;
	}
	printf("Next date is %d/%d/%d\n", day, month, year);
}
int maxdays(int m, int y) { 			//calculate maximum days in a month.
	int num;
	if (m==2) {
		num=febdays(y);
		return num;
	}
	if((m==4)||(m==6)||(m==9)||(m==11)){
		return 30;
	}
	return 31;
}
int febdays(int yr) {					//calculate number of days in feb.
	if (yr%100==0) {
		return 28;
	}
	if (yr%4==0) {
		return 29;
	}
}
