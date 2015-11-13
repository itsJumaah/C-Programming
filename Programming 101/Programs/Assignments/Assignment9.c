#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convLower(char *word);
void header();
int i;												//Global variable.

int main() {
	FILE *data;										//Local variables.
	int w1Count=0, w2Count=0, lineCount=0, j=0, length=0;
	char w1[80], w2[80], w1bkup[80], w2bkup[80], fileName[80], line[1000], linebkup[1000], temp[100];
	system("color 1b");							//Coloring the consol.
	header();
	printf("Enter the name of the file: ");
	gets(fileName);
	data=fopen(fileName, "r");					//Open the file for reading.
	if(data==NULL) {								//File validation.
		system("cls");								//Clear the screen.
		header();
		printf("** ERROR: cannot open %s **\n", fileName);
		system("pause");							//Pause system, press any key..
		exit(0);
	}
	printf("Enter the first word: ");
	gets(w1);
	strcpy(w1bkup, w1);
	convLower(w1);
	printf("Enter the second word: ");
	gets(w2);
	strcpy(w2bkup, w2);
	convLower(w2);
	system("cls");
	header();
	while(fgets(line, 1000, data)!=NULL) {	//Get all the lines from the file.
		lineCount++;
		strcpy(linebkup, line);
		convLower(line);
		length=strlen(line);
		for(i=0; i<length; i++) {				//Copies words from line to temp.
			temp[j]=line[i];
			if((line[i]==' ')||(line[i]=='.')||(line[i]=='\0')||(line[i]=='\n')) {
				temp[j]='\0';
				j=0;
				if(strcmp(temp, w1)==0) {
					if(w1Count==0) {
						printf("The word \'%s\' first appears in line %d which is:\n%s\n\n", w1bkup, lineCount, linebkup);
					}
					w1Count++;
				}
				if (strcmp(temp, w2)==0) {
					if(w2Count==0) {
						printf("The word \'%s\' first appears in line %d which is:\n%s\n\n", w2bkup, lineCount, linebkup);
					}
					w2Count++;
				}
			}
			else {
				j++;
			}
		}
	}
	if(w1Count>0) {
		printf("The word \'%s\' appears %d times in the file.\n", w1bkup, w1Count);
	}
	else {
		printf("The word \'%s\' does not appear in the file.\n", w1bkup);
	}
	if(w2Count>0) {
		printf("The word \'%s\' appears %d times in the file.\n", w2bkup, w2Count);
	}
	else {
		printf("The word \'%s\' does not appear in the file.\n", w2bkup);
	}
	fclose(data);
	system("pause");
	exit(1);
}	
/*---------Converting to lowercase function---------*/
void convLower(char *word) {
	for(i=0; word[i]!='\0'; i++) {
		if((word[i]>='A')&&(word[i]<='Z')) {
			word[i]=word[i]+32;
		}
	}
	word[i]='\0';
}
/*--------------------THE HEADER--------------------*/
void header() {
	printf("SSSSSSS   EEEEEEE     AAA     RRRRRR     CCCCCC   HH   HH\n");
	printf("SS        EE         AA AA    RR   RR   CC        HH   HH\n");
	printf("SSSSSSS   EEEEEEE   AA   AA   RRRRRR    CC        HHHHHHH\n");
	printf("     SS   EE        AAAAAAA   RR  RR    CC        HH   HH\n");
	printf("SSSSSSS   EEEEEEE   AA   AA   RR   RR    CCCCCC   HH   HH\n\n\n\n");
}
