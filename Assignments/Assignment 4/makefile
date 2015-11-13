assign4.exe : assign4.o dir.o fat.o
	gcc -o assign4.exe assign4.o dir.o fat.o

assign4.o : assign4.c
	gcc -c assign4.c
dir.o : dir.c assign4.h
	gcc -c dir.c
fat.o : fat.c assign4.h
	gcc -c fat.c
