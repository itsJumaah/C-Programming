fp.exe : fp.o
	gcc -o fp.exe fp.o
   
fp.o : fp.c
	gcc -c fp.c
   