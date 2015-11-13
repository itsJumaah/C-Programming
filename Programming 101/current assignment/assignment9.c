#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SWAG(char *word);
int i;
int main() {
	FILE *data;
	bool wordFound;
	int w1Count=0, w2Count=0, lineCount=0;
	char w1[80], w2[80], w1bkup[80], w2bkup[80], fileName[80], line[1000], linebkup[1000], temp[100];
	system("color 1b");
	printf("Enter the name of the file: ");	//read in the filename for reading (fgets)
	gets(fileName);
	data=fopen(fileName, "r");
	if(data==NULL) {
		system("cls");
		printf("** ERROR: cannot open %s ** ", fileName);
		system("pause");
		exit(0);
	}
	printf("Enter the first word: ");
	gets(w1);
	strcpy(w1, w1bkup);								//make copies of w1 & w2 (for print out purpose)
	SWAG(w1);
	printf("Enter the second word: ");
	gets(w2);
	strcpy(w2, w2bkup);
	SWAG(w2);						// i feel confident up to here, it should be working, not test yet!

	//check
	wordFound=false;
	while(fgets(line, 1000, data)!=NULL) {
		for(i=0; i<1000; i++) {
			linebkup[i]=line[i];
			if(line[i]=='\n') {				//get rid of \n replace it with \0
				line[i]='\0';
				lineCount++;
			}
		}
		SWAG(line);
		for(i=0; i<1000; i++) { /* needs some changes according to ursula */
			temp[i]=line[i];
			if((line[i]==' ')||(line[i]=='.')||(line[i]=='\0')||(line[i]=='\n')) {
				break;
			}
		}
		if((strcmp(w1, temp)==0)||(strcmp(w2, temp)==0)) {
			wordFound=true;
			if(temp==w1) {
				w1Count++; /* some bullshit from me not working */
				printf("The word \'%s\' first appears in line %d which is:\n %s", w1bkup, lineCount, linebkup);
			}
			else {
				w2Count++;
				printf("The word \'%s\' first appears in line %d which is:\n %s", w2bkup, lineCount, linebkup);
			}
		}
		if(wordFound==true) {
			if(temp==w1) {
				printf("The word \'%s\' appears %d times in the file.\n", w1bkup, w1Count);
			}
			else if(temp!=w1) {
				printf("The word \'%s\' does not appear in the file.", w1bkup);
			}
			else if(temp==w2) {
				printf("The word \'%s\' appears %d times in the file.\n", w2bkup, w2Count);
			}
			else {
				printf("The word \'%s\' does not appear in the file.", w2bkup);
			}
		}
	}
}

/* Codes acording to the tut sheet */
/*		if((line[i]==' ')||(line[i]=='\0')) {
			if (line[i]=='.') {
				line[i]='\0';
			}
			else {
				for(i=0; i<1000; i++) {
					if((line[i]==' ')||(line[i]=='\0')) {
						line[i]='\0';
					}								//end word with \0 over ' ' or \0
				} 
			}
			if(line==w1) {
				if(w1==0) {
					printf("idk wtf is going on");
				}
			}
		//if/else - final print out
		}
	} */


void SWAG(char *word) {
	for(i=0; word[i]!='\0'; i++) {
		if((word[i]>='A')&&(word[i]<='Z')) {
			word[i]=word[i]+32;
		}
	}
	word[i]='\0';
} 
