#include<stdio.h>
#include<windows.h>
int year, mon, day, a, b, c, d, e;
int main() {
	system("color 1b");
	while(4>2){
		printf("Enter the year: ");
		scanf("%d", &year);
		a=year%19;
		b=year%4;
		c=year%7;
		d=(19*a+24)%30;
		e=(2*b+4*c+6*d+5)%7;
		day=d+e;
		
		if (day<=31){
			printf("Easter in %d is on March %d\n", year, day+22);
		}
		else if (day>31) {
			printf("Easter in %d is on April %d\n",year, day-31);
		}
	}
}