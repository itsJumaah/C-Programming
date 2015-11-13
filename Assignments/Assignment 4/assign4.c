#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include "assign4.h"
int main() {
	int i, k;
	char input[100];
	char command[10], filename[50];
	fdir = fopen("dir.dat","r");
	if(fdir == NULL) {
		printf("ERROR: cannot open dir.dat\n");
	}
	ffat = fopen("fat.dat","r");
	if(ffat == NULL) {
		printf("ERROR: cannot open fat.dat\n");
	}	
	read_fat();
	read_dir();
	for(;;) {
		printf(":");
		gets(input);
		sscanf(input,"%s %s %d",command, filename, &k);
		if(strcmp(command,"sectors") == 0) { 
			if(does_file_exist_in_dir(filename) == -1) {
				printf("File does not exist\n");
			}else { 
				for(i = 0; i < 30; i++) {
					if(strcmp(dir[i],filename) == 0) {
						print_sector_chain(fsect[i]);
						break;
					}
				}
			}
		}
		if(strcmp(command,"delete") == 0) {
			if(does_file_exist_in_dir(filename) == -1) {
				printf("File does not exist\n");
			}else {
				for(i = 0; i < 30; i++) {
					if(strcmp(dir[i],filename) == 0) {
						deallocate_sectors(fsect[i]);
						delete_file_from_dir(i);
						break;
					}
				}
			}
			save_fat();
			save_dir();
		}
		if(strcmp(command,"add") == 0) {
			if(dircnt >= 30) {
					printf("Directory is full\n");
			}else {
				if(k > free_sectors()) {
					printf("Not enough free sectors\n");
				}else {
					if(does_file_exist_in_dir(filename) != -1) {
						printf("File already exists \n");
					}else {
						add_file_to_dir(filename, first_free_sector());
						allocate_sectors(first_free_sector(), k);
						save_dir();
						save_fat();
					}
				}
			}
		}
		if(strcmp(command,"dir") == 0) {
			for(i = 0; i < dircnt; i++) {
				printf("%s %d\n",dir[i], fsect[i]);
			}
		}
		if(strcmp(command,"quit") == 0) {
			system("cls");
			fclose(ffat);
			fclose(fdir);
			exit(69);
		}
	}
}
