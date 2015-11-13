#include <stdio.h>

int main() {
	float x = 0;
	unsigned int *p = (unsigned int *)(&x);
	int i;

	*p=0xc1c40000;
	printf("%g %x\n",x,*p);
	x = 0.5;
	printf("%g %x\n",x,*p);
	x = 1;
	printf("%g %x\n",x,*p);
	x = 2;
	printf("%g %x\n",x,*p);
	x = 0; for (i=0;i<1000;i++) x += 0.1;
	printf("%g %x\n",x,*p);
}
