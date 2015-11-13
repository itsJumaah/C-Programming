#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include "assign4.h"
void read_fat(void) {
	char line[120];
	int i = 0;
	while(fgets(line, sizeof line ,ffat)!=NULL) {
		sscanf(line,"%d", &fat[i]);
		i++;
	}
}
void print_fat() {
	int i = 0;
	for(i; i < 32; i++) {
		printf("%d\n",fat[i]);
	}
}
void save_fat(void) { 
	int i;
	fclose(ffat);	
	ffat = fopen("fat.dat","w+");
	if(ffat == NULL) {
		printf("ERROR: cannot open fat.dat\n");
	}
	for(i = 0; i < 32; i++) {
		fprintf(ffat,"%d\n",fat[i]);
	}
	fclose(ffat);
	ffat = fopen("fat.dat","r");
	if(ffat == NULL) {
		printf("ERROR: cannot open fat.dat\n");
	}
}
int free_sectors(void) { 
	int i,j,fatcount=0;
	for(i = 0, j = 0; i < 32; i++){
		if(fat[i] == 1) {
			fatcount++;
			fatsect[j] = i;
			j++;
		}
	}	
	return fatcount;	
}
int first_free_sector(void) {   
	int i;
	for(i = 0;i < 32;i++) {
		if(fat[i] == 1){ return i; break;}
	}
}
void allocate_sectors(int start_sector, int n) { 
	int i = 0,j = 0;
	if(n > (free_sectors())) {
		printf("Not enough free sectors\n");
	}else{ 
		if(dircnt >= 30 ) {
			printf("Directory is full\n");
		}else{
			for(i = 0; i < (n - 1); i++) {
				fat[start_sector] = fatsect[i + 1];
				start_sector = fatsect[i + 1];
			}
		}
	}
	fat[fatsect[i]] = 0;
	save_fat();
}
void deallocate_sectors(int start_sector) { 
	int nextsect, i = 0;
	for(i = 0; i < 30; i++) {
			nextsect = fat[start_sector];
			fat[start_sector] = 1;
			start_sector = nextsect;
			if(fat[start_sector] == 0) {
				fat[start_sector] = 1;
				break;
			}
	}
	save_fat();
}
void print_sector_chain(int start_sector) { 
	int j = start_sector;
	for(;;) {
		printf("%d ",j);
		j = fat[j];
		if(fat[j] == 0) {
			printf("%d\n", j);
			break;
		}
	}
}
