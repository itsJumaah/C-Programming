// first time using structures :D

#include <stdio.h>
#include <string.h>

struct studentrecord {  //why not pointers?				//its a definition.. its not gonna make anything, ie it wont allocate memory or anything
	char name[50];
	char address[100];
	int assignment[9];
};			// ; has to be behind the }

studentrecord person;			//declaring person as a student record.

int x;
int main() {
	strcpy(person.name, "Gandalf");
	printf("Enter your address: ");
	gets(person.address);
	person.assignment[3]=6;
	printf("%s %s %d", person.name, person.address, person.assignment[3]);
}

	