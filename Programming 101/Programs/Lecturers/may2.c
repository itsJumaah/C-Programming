#include<stdio.h>
#include<string.h>
char *name[1000];
int main() {
	int total, i;					//Local variables for main ONLY.
	bool result;
	printf("Enter names and type STOP to stop");
	total=0;
	while(true) {
		result=readname(total);
		if(result==false) {
			break;
		}
		total++;
	}
	printf("You entered %d names", total);
	printf("All names starting with M\n");
	for(i=0; i<total; i++) {
		if(name[i][0]=='M') {		//i stands for the name i and zero is for the position inside the name
			printf("%s\n", name[i]);
		}
	}
}
bool readname(int index) {
	int numbytes;
	char temp[92];
	gets(temp);
	if(strcmp(temp, "STOP")==0) {
		return false;
	}
	numbytes=strlen(temp)+1;
	name[index]=(char*)malloc(numbytes);
	strcpy(name[index], temp);
	return true;
}