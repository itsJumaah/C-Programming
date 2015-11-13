#include<stdio.h>
float total, avg;
float rain[12];
int index;
int main() {
	total=0.0;
	for(index=0; index<12; index++) {
		printf("Enter the rainfall for month %d: ", index+1);
		scanf("%f", &rain[index]);
		total=total+rain[index];
	}
	avg=total/12.0;
	printf("Average rainfall is %1.1f\n", avg);
}