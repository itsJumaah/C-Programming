/*Program written by Bilal Jumaah 12232659*/
//			Assignment 8.0

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void header();
void stringcat(char *first, char *second);
void stringcopy(char *first, char *second);
int stringlength(char *str);
int stringcompare(char *first, char *second);

int main() {
	int strLength, output;
	char usrChoice, strInput[300],strInput2[300], strOutput[300], yn;
	system("color 1b");																		//Color the console.
	while(true) {
		header();
		usrChoice=getch();																	//Read in user choice
		if(usrChoice=='A'||usrChoice=='a') {											//If user chooses A, StringCOPY
			system("cls");																		//Clear screen.
			printf("A. Test the stringcopy function.\n"); 
			printf("Please type-in your string: ");
			gets(strInput);																	//Read in string
			stringcopy(strOutput, strInput);												//Call the function
  			printf("\nThe copied string is \"%s\"\n\n\n", strOutput);			//Print effect
			system("pause");																	//Pause, press any key to cont.
		}
  		else if(usrChoice=='B'||usrChoice=='b') {										//If user chooses B, StringLENGTH
			system("cls");
			printf("B. Test the stringlength function.\n"); 
  			printf("Please type-in your string: ");
  			gets(strInput);
  			strLength=stringlength(strInput);
  			printf("\nThe string \"%s\" has a length of (%d) characters.\n\n\n", strInput, strLength);
			system("pause");
		}
  		else if(usrChoice=='C'||usrChoice=='c') {										//If user chooses C, StringCAT
  			system("cls");
			printf("C. Test the stringcat function.\n");
			printf("Please type-in your first string: ");
			gets(strInput);
			printf("Please type-in your second string: ");
			gets(strInput2);
			stringcat(strInput, strInput2);
			printf("\nThe strings combination is \"%s\".\n\n\n", strInput);
			system("pause");
		}
  		else if(usrChoice=='D'||usrChoice=='d') {										//If user chooses D, StringCOMPARE
			system("cls");
			printf("D. Test the stringcompare function.\n");
			printf("Please type-in your first string: ");
			gets(strInput);
			printf("Please type-in your second string: ");
			gets(strInput2);
			output=stringcompare(strInput, strInput2);
			if(output>0) {
				printf("\n%s is alphabetically \"better\" than %s\n\n\n", strInput2, strInput);
			}
			else if(output==0) {
				printf("\nThe strings are pretty much alphabetically equal!\n\n\n");
			}
			else {
				printf("\n%s alphabetically \"better\" than %s\n\n\n", strInput, strInput2);
			}
			system("pause");
		}
  		else if(usrChoice=='Q'||usrChoice=='q') {										//If user chooses Q, confirmation?
			while(true) {
				system("cls");
				printf("Are you sure you want to quit this program?(Y/N)");
				yn=getch();
				if(yn=='Y'||yn=='y') {
				exit(0);																			//Quit.
				}
				else if(yn=='N'||yn=='n') {
					system("cls");
					break;
				}
				else {
					system("cls");
					continue;
				}
			}
		}
  		else {																					//User chooses other char.
			system("cls");
  			printf("You have entered an unrecognized character. ");
			system("pause");
  		}
	}
}
/*--------StringLENGTH Function--------*/
int stringlength(char *str) {
	int len;
	for (len=0; str[len]!=('\0'); len++) {
	}
	return len;
}
/*--------StringCOPY Function--------*/
void stringcopy(char *first, char *second) {
  int i;
  for (i=0; i<stringlength(second); i++) {
    first[i]=second[i];
  }
  first[i]='\0';
}
/*--------StringCAT Function--------*/
void stringcat(char *first, char *second) {
	int i, j=0, totalStrLen=(stringlength(first)+stringlength(second));
	for(i=stringlength(first); i<totalStrLen; i++) {
		first[i]=second[j];
		j++;
	}
	first[i]='\0';
}
/*--------StringCOMPARE Function--------*/
int stringcompare(char *first, char *second)	{
	int i=0;
	while(first[i]==second[i]) {
		if(first[i]=='\0') {
			return first[i]-second[i];
		}
		i++;
	}
	return first[i]-second[i];
}	
/*--------HEADER Function--------*/
void header() {
	system("cls");	
	printf("BBBBBBBB   BBBBBBBB   BBBBBB     BBBBBB   BBB   BB   BBBBBBBB        BB\n");
	printf("BB            BB      BB    BB     BB     BBBB  BB   BB              BB\n");
	printf("BBBBBBBB      BB      BBBBBB       BB     BB BB BB   BB  BBBB        BBBBBBBB\n");
	printf("      BB      BB      BB    BB     BB     BB  BBBB   BB    BB        BB    BB\n");
	printf("BBBBBBBB      BB      BB    BB   BBBBBB   BB   BBB   BBBBBBBB   BB   BB    BB\n");
	printf("***************************************\n");
	printf("* A. Test the stringcopy function.    *\n");
	printf("* B. Test the stringlength function.  *\n");
	printf("* C. Test the stringcat function.     *\n");
	printf("* D. Test the stringcompare function. *\n");
	printf("* Q. Quit.                            *\n");
	printf("***************************************\n\n");
}
