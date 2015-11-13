#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *mainFile, *alFile, *mzFile;
int main() {
	char name[100];
	mainFile=fopen("Name.txt", "r");
	if(mainFile==NULL) {
		printf("Error: can not open Name.txt\n");
		exit(99);
	}
	alFile=fopen("A-L.txt", "w");
	mzFile=fopen("M-Z.txt", "w");
	while(fgets(name, 100, mainFile)!=NULL) {
		if((name[0]>='A')&&(name[0]<='L')) {
			fprintf(alFile, "%s", name);
		}
		else {
			fprintf(mzFile, "%s", name);
		}
	}
	fclose(mainFile);
	fclose(alFile);
	fclose(mzFile);
}