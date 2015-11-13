/*This program written by Bilal Jumaah 12232659*/
#include<stdio.h>
int year, mon, day;
bool leapyear;
int main() {
	printf("Enter a date in the form day/month/year: ");
	scanf("%d/%d/%d", &day, &mon, &year);
	if (year%4==0) {			/*Leap year code begins*/
			if (year%100==0) {
				if (year%400==0) {
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
	}                       /*Leap year code ends*/
	
	day++;					/*General day equation*/
	
	if ((mon==4)||(mon==6)||(mon==9)||(mon==11)) {	/*months have 30 days equations*/
		if (day==31) { 
			day=1;
			mon++;
		}
	}
	else if (mon==2) {		/*Feb equations*/
		if (leapyear==true) {
			if (day==30) {
			day=1;
			mon++;
			}
		}
		else {
			if (day==29) {
			day=1;
			mon++;
			}
		}
	}
	else {						/*Rest of months equations*/
		if (day==32) {
			day=1;
			mon++;
		}
		if (mon==13) {
			mon=1;
			year++;
		}
	}								/*If statments (Equations) ends*/
	printf("The date of the next day will be: %d/%d/%d\n\n", day, mon, year);
}
