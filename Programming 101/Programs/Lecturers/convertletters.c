#include<stdio.h>
#include<conio.h>
char letter;
int main() {
	printf("Type a letter (press a key): ");
	letter=getch();
	if((letter>='a')&&(letter<='z')){
		letter=letter-32;
		printf("The capital letter is %c", letter);
	}
	else {
		printf("You did not enter a lower case letter");
	} 
}