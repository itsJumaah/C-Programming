/*Program written by Bilal Jumaah 12232659 */
//          Assignment 10.2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct data {			//Data structure.
  char name[180];
  char phone[20];
};
							//Functions declaration.
void displaydetails(data *phonelst, int x, int n);
data getdetails(char *line);
void header();
void search(char *nameS, int counter, data phonlist[1000]);
void convLower(char *word);


int main() {
	int count, i;
	char usrChoice, yn, line[200], name[180];
	data phonelist[1000];
	FILE *f;
	
	system("color 1b"); //concole color.
	
	f=fopen("phonelist.txt", "r");
	i=0;
	while(fgets(line, 200, f)!=NULL) {
		phonelist[i]=getdetails(line); 
		i++;
	}
	count=i;
	fclose(f); 			  	//closing the file.
	while(true) {
		system("cls");		//clear screen.
		header();
		usrChoice=getch();
		if((usrChoice=='A')||(usrChoice=='a')) {
			system("cls");
			printf("A. Search for a name.\n");
			printf("Enter name to search for: ");
			gets(name);
			search(name, count, phonelist);
			printf("\n\n\n");
			system("pause");
		}
		else if((usrChoice=='B')||(usrChoice=='b')) {
			system("cls");
			printf("You're contacts are:\n");
			printf("--------------------\n\n");
			displaydetails(phonelist, 0, count);
			system("pause");
		}
		else if((usrChoice=='C')||(usrChoice=='c')) {
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
			printf("You have entered unrecognized character.\n\n\n");
			system("pause");
		}
	}
}
/*------------------GetDetails Function------------------*/
data getdetails(char *line) {
	data person;
	int j=0, i=0; 
	for(i=0; line[i]!=';'; i++) {
		person.name[i]=line[i];
	}
	person.name[i]='\0';
	i++;
	while(line[i]!='\0') {
		person.phone[j]=line[i];
		i++;
		j++;
	}
	person.phone[j-1]='\0';
	return person; 
}
/*------------------------Header-------------------------*/
void header() {
	printf("CCCCCC  OOOOOO  NN  NN  TTTTTT  AAAAAA  CCCCCC  TTTTTT  SSSSSS\n");
	printf("CC      OO  OO  NNN NN    TT    AA  AA  CC        TT    SS\n");
	printf("CC      OO  OO  NN NNN    TT    AAAAAA  CC        TT    SSSSSS\n");
	printf("CC      OO  OO  NN  NN    TT    AA  AA  CC        TT        SS\n");
	printf("CCCCCC  OOOOOO  NN  NN    TT    AA  AA  CCCCCC    TT    SSSSSS\n\n");
	printf("********************************\n");
	printf("* A. Search for a name.        *\n");
	printf("* B. Display all contact list. *\n");
	printf("* C. Quit.                     *\n");
	printf("********************************\n\n\n");
}
/*-------------------Display Function--------------------*/
void displaydetails(data *phonelst, int x, int n) {
	int j, i;
	data temp;
	for(i=(1+x); i<(x+n); i++) {
		for(j=(x+n-1); j>=i; j--) {
			if(strcmp(phonelst[j-1].name, phonelst[j].name)>0) {
				temp=phonelst[j-1];
				phonelst[j-1]=phonelst[j];
				phonelst[j]=temp;
			}
		}
	}
	for(i=0; i<n; i++) {
		printf("%s\n", phonelst[i].name);
	}
	printf("\n\n");
}
/*--------------------Search Function--------------------*/
void search(char *nameS, int counter, data *phonlist) {
	int i;
	bool nameFound;
	data phonelistbkup[1000];
	nameFound=false;
	convLower(nameS);
	for(i=0; i<counter; i++) {
		strcpy(phonelistbkup[i].name, phonlist[i].name);
		convLower(phonelistbkup[i].name);
		if(strcmp(phonelistbkup[i].name, nameS)==0) {
			printf("%s's phone number is %s\n", phonlist[i].name, phonlist[i].phone);
			nameFound=true;
			break;
		}
	}
	if(nameFound==false) {
		printf("The name you're looking for doesn't exist!\n");
	}
}
/*-----------Converting to lowercase function------------*/
void convLower(char *word) {
	int i=0;
	for(i=0; word[i]!='\0'; i++) {
		if((word[i]>='A')&&(word[i]<='Z')) {
			word[i]=word[i]+32;
		}
	}
	word[i]='\0';
}
