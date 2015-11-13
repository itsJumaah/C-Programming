#include<stdio.h>
#include<windows.h>
#include<conio.h>
char k;
int main() {
	system("color 1b");
	while(1==1){
	printf("Type one character (Press a key): ");
	k=getch(); /*input character*/
	printf("The character %c has the code %d\n", k, k);
}
}
