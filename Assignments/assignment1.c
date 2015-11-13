/*---------------Program written by Bilal Jumaah 12232659---------------*/
// 	Assignment 1.0 - Converting decimal to binary and binary to decimal
  
#include <stdio.h>   
  
int convToBinary(int dec);   
int convToDecimal(int bin);   
  
int main() {   
	char DorB[10], input[10000];   
	int output, i, intput, valid, valid2;   

	printf("Type in a number: ");   
	gets(input);   
	valid=1;											//ie. true
	valid2=1;  

	for(i=0; input[i]!='\0'; i++) { 			//loop to validate the input
		if(input[i]<48) {   
			valid=0;   								//ie. false
		}   
		else if(input[i]>57) {   
			valid=0;   
		}  
	}  

	for(i=0; input[i]!='\0'; i++) {			//loop to validate the binary starts with 0
		if(input[i]!='0'&&input[i]!='1') {   
			valid2=0;   
		}   
	}  

	if(valid==1) {
		sscanf(input, "%d", &intput);   		//convert the string input to integer
		if(input[0]=='1'){   
			printf("Is this number decimal (d) or binary (b)?");   
			gets(DorB);   
			if(DorB[0]=='b'||DorB[0]=='B'){   
				if(intput<=11111111&&intput>=00000000) {   
					output=convToDecimal(intput);   
					printf("Converting binary to decimal. Answer is: %d", output);   
				}  
				else {   
					printf("That is an invalid number!");   
				}  
			}   
			else if(DorB[0]=='d'||DorB[0]=='D'){   
				if(intput<=255&&intput>=1) {   
					output=convToBinary(intput);   
					printf("Converting decimal to binary. Answer is: %08d", output);   
				}  
				else {   
					printf("That is an invalid number!");   
				}  
			}   
		}   
		else if(input[0]=='0'){   
			if(valid2==1&&intput<=11111111&&intput>=00000000) {   
				output=convToDecimal(intput);   
				printf("Converting binary to decimal. Answer is: %d", output);  
			}  
			else {   
				printf("That is an invalid number!");   
			}                     
		}                 
		else {    
			if(intput<=255&&intput>=2) {   
				output=convToBinary(intput);   
				printf("Converting decimal to binary. Answer is: %08d", output);   
			}  
			else {   
				printf("That is an invalid number!");   
			}  
		}   
	}    
	else {   
		printf("That is an invalid number!");   
	}   
}   
/*----Converting decimal to binary funtion----*/
int convToBinary(int dec) {   
	int rem, i=1, bin=0;   
	while(dec!=0) {   
		rem=dec%2;   
		dec=dec/2;   
		bin=bin+rem*i;   
		i=i*10;   
	}   
	return bin;   
}   
/*----Converting binary to decimal funtion----*/
int convToDecimal(int bin) {  
	int rem, i=1, dec=0;  
	while(bin!=0){  
		rem=bin%10;  
		dec=dec+rem*i;  
		i=i*2;  
		bin=bin/10;  
	}  
	return dec;  
}
