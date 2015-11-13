
#include<stdio.h>
#include<windows.h>
int year, mon, day;
bool leapyear;
int main() {
	system("color 1b");
	while(1==1){
		printf("Enter the day: ");
		scanf("%d/ %d/ %d", &day, &mon, &year);
		if (year % 4 == 0) {
			if (year % 100 == 0){
				if (year % 400 == 0) {
					leapyear=true;
				}
				else {
					leapyear=false;
				}
			}
			else {
				leapyear=true;
			}
		}
		else {
			leapyear=false;
		}
		if ((leapyear==true) && (day==28) && (mon==2)){
			printf("the next day is 29/2/%d", year);
		}
		else{
			printf("next day is %d/ %d/ %d/", day+1, mon, year);
		}
	}
}