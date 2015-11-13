#include <stdio.h>

int main() {
	unsigned char c = 0x41, d;
	int i;
	
	for (i=0;i<220;i++) {
		printf("%4d",c);
		d = ((c >> 5) ^ c) & 0x01;
		c = c >> 1;
		c = c | (d << 7);
	}
	printf("\n");
}
