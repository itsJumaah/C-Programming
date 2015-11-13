#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include "assign4.h"
char line[120], linex[120];
void read_dir(void) {
	int i = 0;
	while(fgets(line,sizeof line,fdir)!=NULL) {
		sscanf(line,"%s %d",dir[i], &fsect[i]);
	
		i++;
	}
	dircnt = i;
	save_dir();
}

void save_dir(void) {
	int i = 0;
	fclose(fdir);
	fdir = fopen("dir.dat","w+");
	if(fdir == NULL) {
		printf("ERROR: cannot open dir.dat\n");
	}
	for(i = 0; i < dircnt; i++) {
		fprintf(fdir,"%s %d\n",dir[i],fsect[i]);
	}
	fclose(fdir);
	fdir = fopen("dir.dat","r");
	if(fdir == NULL) {
		printf("ERROR: cannot open dir.dat\n");
	}
}

void print_dir(void) {
	int i = 0;
	for(i; i < dircnt; i++) {
		printf("%s\n",dir[i]);
	}
}

int does_file_exist_in_dir(char *file) {
	int i=0, j = 0,temp=0;
	while(i < (dircnt)) {
		if(strcmp(dir[i],file) == 0) {
			temp++;
			break;
		}
		i++;
	}
	if(temp==1) {
			return fsect[i]; 
		}else{
			return -1;
		}
}


void add_file_to_dir(char *file, int start_sector) {
		if(does_file_exist_in_dir(file) != -1) {
			printf("File already exists\n");
		}else { 
			strcpy(dir[dircnt],file);
			fsect[dircnt] = start_sector;
			dircnt++;
			}
	save_dir();
}

void delete_file_from_dir(int position) {
	int i = 0, j = 1;
	for(i = 0; i < dircnt; i++) {
		strcpy(dir[position], dir[position + 1]);
		fsect[position] = fsect[position + 1];
		position++;
		j++;
		
	}
	dircnt --;
	save_dir();
}
