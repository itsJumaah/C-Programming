#include<stdio.h>
#include<string.h>
void stringcopy(char *first, char *second) {
	int i;
	for(i=0; i<strlen(second); i++) {
		first[i]=second[i];
	}
	first[i]='\0';			//what is \0??
}