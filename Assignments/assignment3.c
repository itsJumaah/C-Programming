#include <stdio.h>

int main() {

	unsigned char pCounter, memory[255], pRegister[16]={0};
	unsigned int temp;
	int i, one, two, three, four, threenfour, mask1, mask2;
	FILE *f;

	temp=0;
	i=0;
	pCounter=0;	 
	mask1=0xFF00;
	mask2=0X00FF;

	f=fopen("a3.txt", "r");

	while(fscanf(f, "%x", &temp)!= EOF){   
		memory[i]=(temp&mask1)>>8;
		memory[i+1]=(temp&mask2);
		i=i+2;
	}

	while (memory[pCounter]!=0xC0){
		printf("%02X %X%02X - [", pCounter, memory[pCounter], memory[pCounter+1]);
		for(i=0; i<15; i++){
			printf("%02X ", pRegister[i]);
		}
		printf("%02X]\n", pRegister[15]);
		// Assigning the variables and giving them their values.
		one=(memory[pCounter]&0xF0)>>4;
		two=(memory[pCounter]&0xF);
		three=(memory[pCounter+1]&0xF0)>>4;
		four=(memory[pCounter+1]&0xF);
		threenfour=(memory[pCounter+1]);
		pCounter=pCounter+2;
		// the instructions.
		if(one==0x01){
			pRegister[two]=memory[threenfour]; 
		}
		else if(one==0x02){
			pRegister[two]=threenfour;
		}
		else if(one==0x03){
			pRegister[threenfour]=memory[two];
		}
		else if(one==0x04){
			pRegister[four]=pRegister[three];
		}
		else if(one==0x05){
			pRegister[four]=pRegister[two]+pRegister[three];
		}
		else if(one==0x07){
			pRegister[four]=pRegister[two]|pRegister[three];
		}
		else if(one==0x08){
			pRegister[four]=pRegister[two]&pRegister[three];
		}
		else if(one==0x09){
			pRegister[four]=pRegister[two]^pRegister[three];
		}
		else if(one==0x0A){                
			pRegister[two]=(pRegister[two]>>four)|(pRegister[two]<<8-four);
		}
		else if(one==0x0B){
			if(pRegister[two]==pRegister[0]){
				pCounter=threenfour;
			}
		}
	}
	printf("%02X C000 - [", pCounter);
		for(i=0; i<15; i++){
			printf("%02X ", pRegister[i]);
		}
	printf("%02X]\n", pRegister[15]);
}

