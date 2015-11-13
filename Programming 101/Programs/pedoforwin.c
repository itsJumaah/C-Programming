/*Made by FishHunters, all credits go to B1lal Jum44H, Thomas J., Ashneel K.*/
#include<stdio.h>
#include<windows.h>
int yourage, herage, legalage;
int main() {
	system("color 1b");
	while(1<2) {
	printf("This program was made to tell you \nif you're allgoods with the\nchick you planning to get with.\n\n");
	printf("Enter your age: ");
	scanf("%d", &yourage);
	printf("Enter her age: ");
	scanf("%d", &herage);
	
	legalage=(yourage/2)+7;
		
	if (yourage<=13) {
		printf("Go home kid!");
	}
	else if (herage>yourage) {
		printf("You're whiped bro!");
	}
	else if ((herage)>=(legalage)||(herage==yourage)) {
		printf("Your allgood ge");
	}
	else {	
		printf("You're pedo motherfucker!\nShe's only %d years old bro!", herage);
	}
	printf("\n\n\n\nFishHunters copyright 2013 © All rights reserved.\n\n");
	
}
}
