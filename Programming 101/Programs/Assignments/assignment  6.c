/* Program written by Bilal Jumaah 12232659 */
//		Assignment 6.0
#include<stdio.h>
#include<math.h>
int i, error;
void typefault10(float volt);
void typefault15(float volt, float volt2);
float total, av, tenp, fifteenp, v[6];
int main() {
	printf("Enter the voltages below: \n");			//collecting the data from the user.
	total=0.0;
	error=0;
	for(i=0; i<6; i++) {
		printf("Hour %d: ", i+1);
		scanf("%f", &v[i]);
		total=total+v[i];
	}
	av=total/6.0;
	tenp=av*0.1;									//calculate %10 of the average.
	fifteenp=av*0.15;								//calculate %15 of the average.
	printf("\n\nThe average is %1.1f volts\n\n10%% = %1.1f volts.\n15%% = %1.1f volts.", av, tenp, fifteenp);
	for(i=0; i<6; i++) {							//loop runs x6 to validate the problems of %10.
		typefault10(v[i]);
	}
	for(i=0; i<5; i++) {							//loop runs x5 to validate the problems of %15.
		typefault15(v[i], v[i+1]);
	}
	if(error==0) {
		printf("\n\nNo problems were encountered.\n\n");
	} 
}
void typefault10(float volt) {						//local function to encounter the %10 problems.
	float dif;
	dif=volt-av;
	if(fabs(dif) > tenp) {
		if (error==0) {
			printf("\n\nThe following problems occurred:\n");
		}
		error++;
		printf("%d. Voltage at hour %d was %1.1f volts (difference of %1.1f volts).\n", error, i+1, volt, fabs(dif));
	}
}
void typefault15(float volt, float volt2) {			//local function to encounter the %15 problems.
	float diff;
	diff=volt-volt2;
	if (fabs(diff) > fifteenp) {
		if(error==0) {
			printf("\n\nThe following problems occurred:\n");
		}
		error++;
		printf("%d. Voltage change from hour %d to hour %d was %1.1f volts.\n", error, i+1, i+2, fabs(diff));
	} 
}