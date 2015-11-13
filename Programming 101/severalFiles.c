#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *numFile;
int a, b, result;
char fileName[50], line[60];
//example line:	23	45

int main() {
	strcpy(fileName, "Nums.txt");
	numFile=fopen(fileName, "r");
	if(numFile==NULL) {
		printf("ERROR: can not open %s", fileName);
		exit(19);
	}
	while(fgets(line, 60, numFile)!=NULL) {
		sscanf(line, "%d %d", &a, &b);
		result=a+b;
		printf("%d + %d = %d\n", a, b, result);
	}
	fclose(numFile);
}
