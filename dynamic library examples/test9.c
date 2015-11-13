#include <stdio.h>
#include "dlfcn.h"

void *handle;
void (*fp)(void);
char function_name[80];

int main() {
	printf("Which function: ");
	gets(function_name);
	handle = dlopen("f_dynamic.dll", 0);
	fp = dlsym(handle, function_name);
	fp();
}
