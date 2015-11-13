#include <stdio.h>

int main() {
	char s[80],t[80];
	int day,month,year;
	
	printf("%d\n",scanf("%d%*1[.:]%d%*1[.:]%d",&day,&month,&year));
//	printf("%d\n",scanf("..%s%*c",s));
	gets(t);
	printf(":%s:\n",t);
}
