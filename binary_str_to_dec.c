#include <stdio.h>

int main() {
	int result,i;
	char s[80];
	
	result = 0;
	printf("type in a number:");
	gets(s);
	i = 0;
	while (s[i] != '\0') {
		result = result*2;
		result = result + s[i] - '0';
		i++;
	}
	printf("result = %d\n",result);
}
