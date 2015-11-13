#include <stdio.h>
void read_dir(void);												
void save_dir(void);												
void print_dir(void);											
int  does_file_exist_in_dir(char *file);					
void add_file_to_dir(char *file, int start_sector);	
void delete_file_from_dir(int position);					
void read_fat(void);												
void save_fat(void);												
int  free_sectors(void);										
int  first_free_sector(void);									
void allocate_sectors(int start_sector, int n);			
void deallocate_sectors(int start_sector);				
void print_sector_chain(int start_sector);			
void print_fat();

FILE *ffat;
FILE *fdir;
int fat[32];
char dir[30][30];
int dircnt;
int fsect[32];
int fatsect[32];
