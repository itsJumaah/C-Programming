/*Program written by Bilal Jumaah 12232659*/
#include <stdio.h>
int jud, count;
float mark, total, average, max, min;
int main() {
	printf("Enter the number of judges: ");
	scanf("%d", &jud);
	
	while(true) { 										// loop to validate judges.
		if((jud>=4)&&(jud<=8)) {
			break;
		}
		else {
			printf("You have entered an incorrect number of judges\nIt must be between 4 and 8, please try again.\n\nEnter the number of judges: ");
			scanf("%d", &jud);
		}
	}

	total=0.0;
	max=0.0;
	min=10.0;
	
	for(count=0; count<jud; count++) {
		printf("Enter the mark of jugde number %d: ", count+1);
		scanf("%f", &mark);
		
		while(true) {									// Loop to validate the mark.
			if((mark>=0.0)&&(mark<=10.0)) {
				break;									// Get out of the loop since the mark within the range.
			}
			else {
				printf("You have entered a mark out of the rage from 0.0 to 10.0.\n\nPlease try again: ");
				scanf("%f", &mark);
			}
		}
		total=total+mark;
		if(mark>max) {									// Finding the maximum mark.
			max=mark;
		}
		if(mark<min) {									// Finding the minimum mark.
			min=mark;
		}
	}
	total=total-(min+max);							// Calculate the total exclude maximum and minimum.
	average=total/(jud-2);							// Judges-2 because the minimum and maximum are excluded.
	printf("\nThe highest mark is %1.1f\n", max);
	printf("The lowest mark is %1.1f\n", min);
	printf("The final mark is %1.1f\n", average);
}