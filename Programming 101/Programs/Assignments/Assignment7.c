#include <stdio.h>
#include <string.h>

int width, length, gaps, gaplength, odds, i, temp, header, extra;
char sentence [100];
int main () {
   printf ("Enter the width of the collumn.\n");
   scanf ("%d", &width);
   printf ("Enter in the line of text.\n");
	getchar ();
   while (true) {
		gets (sentence);
		length = strlen (sentence);
		if (length > width) {
			printf("Text is longer than collumn width, try again.\n");
		}
		else{
			break;
		}
   }
   gaps = 0;
   i = 0;
   for (i=0; sentence [i]!='\0'; i++) {
		if (sentence[i] == ' ') {
			gaps++;
		}
   }
	header = 0;
	for(i=0; i < width; i++) {
		printf ("%d", header);
		header++;
		if (header == 10) {
			header = 0;
		}
	}
   printf ("\n");
	extra = width - length;
	gaplength = extra/gaps;
	odds = extra % gaps;

	for (i=0; sentence[i]!='\0'; i++) {
		printf ("%c", sentence [i]);
		if (sentence [i] == ' ') {
			for (temp=0; temp < gaplength; temp++) {
				printf (" ");
			}
			if (odds > 0) {
				printf (" ");
				odds--;
			}
		}	
	}
}