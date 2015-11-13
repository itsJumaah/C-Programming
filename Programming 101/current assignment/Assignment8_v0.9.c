/*Program written by Bilal Jumaah 12232659*/
//			Assignment 8.0
//				v0.9
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void stringcopy(char *first, char *second);
int stringlength(char *str);
char* stringcat(char *s, const char *t);
int stringcompare(char *a, char *b);
void header();

int main() {
	int strLength, output;
	char usrChoice, strInput[300],strInput2[300], strOutput[300], yn;	//locals
	char* strOutput2;
	system("color 1b");
	while(true) {
		header();
		usrChoice=getch();																	//read in user choice (getche)
		if(usrChoice=='A'||usrChoice=='a') {											//if(user choice A-D) {  /*5-4 will be needed*/
			system("cls");
			printf("Please type-in your string that you want to be copied: ");
			gets(strInput);															//read in string(s)
			stringcopy(strOutput, strInput);								//call the function
  			printf("\nThe copied string is \"%s\"\n\n\n", strOutput);				//print effect
			system("pause");
		}
  		else if(usrChoice=='B'||usrChoice=='b') {
			system("cls");
  			printf("Please type-in your string that you want to find its length: ");
  			gets(strInput);
  			strLength=stringlength(strInput);
  			printf("\nThe string \"%s\" has a length of (%d) characters.\n\n\n", strInput, strLength);
			system("pause");
		}
  		else if(usrChoice=='C'||usrChoice=='c') {									//is it correct?!
  			system("cls");
			printf("Please type-in your first string: ");
			gets(strInput);
			printf("Please type-in your second string: ");
			gets(strInput2);
			strOutput2=stringcat(strInput, strInput2);
			printf("\nThe strings combination is \"%s\".\n\n\n", strOutput2);
			system("pause");
		}
  		else if(usrChoice=='D'||usrChoice=='d') {
			system("cls");
			printf("Please type-in your first string: ");
			gets(strInput);
			printf("Please type-in your second string: ");
			gets(strInput2);
			output=stringcompare(strInput, strInput2);
			if(output>0) {
				printf("\nThe second string is \"better\" than the first one!\n\n\n");
			}
			else if(output==0) {
				printf("\nThe strings are pretty much equal!\n\n\n");
			}
			else {
				printf("\nThe first string is \"better\" than the second one!\n\n\n");
			}
			system("pause");
		}
  		else if(usrChoice=='Q'||usrChoice=='q') {
			while(true) {
				system("cls");
				printf("Are you sure you want to quit this program?(Y/N)");
				yn=getch();
				if(yn=='Y'||yn=='y') {
				exit(0);											
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
  		else {
			system("cls");
  			printf("You have entered an unrecognized character. ");
			system("pause");
  		}
	}
}
/////////////////////////////////
int stringlength(char *str) {
	int len;
	for (len=0; (*str)!=('\0'); str++) {
		len++;
	}
	return len;
}
/*
int stringlength(char *s) {
	char *p=s;
	while(*p!='\0') {
		p++;
	}
	return(p-s);
} 
*/
/////////////////////////////////
void stringcopy(char *first, char *second) {
  int i;
  for (i=0; i<stringlength(second); i++) {
    first[i] = second[i];
  }
  first[i] = '\0';
}
/////////////////////////////////
char* stringcat(char *s, const char *t) { //lecturer used void function here
	char *p=s;
	if(s==NULL||t==NULL) {
		return s; 									// we need not have to do anything 
	}
	while((*s)!=('\0')) {
		s++;
	}
	while((*t)!=('\0')) {
		*s++=*t++;
	}
	*s='\0';
	return p;
}
/////////////////////////////////
int stringcompare(char *a, char *b)	{
	int i=0;
	while (a[i]==b[i]) {
		if(a[i]=='\0') {
			return a[i]-b[i];
		}
		i++;
	}
	return a[i]-b[i];
}	
/////////////////////////////////
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
