#include<stdio.h>
#include<string.h>
int num, getintvalue();
int main() {
	num=getintvalue();
	printf("The number is %d\n", num);
}
int getintvalue() {
	int value, i;
	bool valid;
	char temp[52];
	while(true) {
		printf("Enter an integer value: ");
		gets(temp);
		valid=true;
		for(i=0; i<strlen(temp); i++) {
			if(temp[i]<48) {
				valid=false;
			}
			else if(temp[i]>57) {
				valid=false;
			}
		}
		if(valid) {
			sscanf(temp, "%d", &value);
			return value;
		}
		else {
			printf("%s is not a number\n", temp);
		}
	}
}