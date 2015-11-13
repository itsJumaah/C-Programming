#include<stdio.h>
int year;
int main() {
	while (2>1){
		
	
		scanf("%d", &year);
	
		if (year %400>0 && year%4>0){
		printf("Not a leap year");
	
			}
	
			else if (year%4>0){
		printf("Not a leap year");
	
				}
	
	
				else {
		printf("a leap year");
	}
}
}