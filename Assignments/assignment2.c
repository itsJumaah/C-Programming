/*------Program written by Bilal Jumaah - 12232659---------*/
//Assignment 2.0 - Expressions and operations dealing with Hexadecimal numbers.

#include <stdio.h>
#include <string.h>

int main() {
	unsigned int i, hex1, hex2, output;
	char inst[10], input[100];
	int signedHex1;							//converting hexadecimal 1 to signed integere.
	
	printf("Type in an expression: ");
	gets(input);
	sscanf(input, "%x %s %x", &hex1, inst, &hex2);
	// The operations.
	if(strcmp(inst, "add")==0) {
		output=hex1+hex2;
		printf("The answer is: %x", output);
	}
	else if(strcmp(inst, "sub")==0) {
		output=hex1-hex2;
		printf("The answer is: %x", output);
	}
	else if(strcmp(inst, "and")==0) {
		output=hex1&hex2;
		printf("The answer is: %x", output);
	}
	else if(strcmp(inst, "or")==0) {
		output=hex1|hex2;
		printf("The answer is: %x", output);
	}
	else if(strcmp(inst, "xor")==0) {
		output=hex1^hex2;
		printf("The answer is: %x", output);
	}
	else if(strcmp(inst, "shl")==0) {
		for(i=0; i<hex2; i++) {
			hex1=hex1<<1;
		}
		printf("The answer is: %x", hex1);
	}
	else if(strcmp(inst, "shr")==0) {
		for(i=0; i<hex2; i++) {
			hex1=hex1>>1;
		}
		printf("The answer is: %x", hex1);
	}
	else if(strcmp(inst, "asr")==0) {
		signedHex1=hex1;
		for(i=0; i<hex2; i++) {
			signedHex1=signedHex1>>1;
		}
		printf("The answer is: %x", signedHex1);
	}
	else if(strcmp(inst, "rol")==0) {
		output=(hex1<<hex2)|(hex1>>32-hex2);
		printf("The answer is: %x", output);
	}
	else if(strcmp(inst, "ror")==0) {
		output=(hex1>>hex2)|(hex1<<32-hex2);
		printf("The answer is: %x", output);
	}
}
