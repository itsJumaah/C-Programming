#include <stdio.h>

void f1(void);
void f2(void);
void (*fp)(void);

int main() {
	fp = &f1;
	fp(); //call f1 using the function ptr
	fp = &f2;
	fp(); //call f2 using the function ptr
}

void f1(void) {
	printf("f1 called\n");
}

void f2(void) {
	printf("f2 called\n");
}
