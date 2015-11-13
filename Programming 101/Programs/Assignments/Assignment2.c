

/* Program written by Bilal Jumaah 12232659 */

#include <stdio.h>
int a, b, c, d, e, result, n, m, y;
int main() {
	printf("Enter the year: ");        /*First output*/
	scanf("%d", &y);                   /*Input*/
	c=y%19;                            /*Equations*/
	d=y%4;
	e=y%7;
	a=(19*c+24)%30;
	b=(2*d+4*e+6*a+5)%7;
	result=22+a+b;
	n=((result%32)+(result/32));
	m=3+result/32;
	printf("Easter Sunday in year %d is day %d of month %d.\n\n", y, n, m);   /*Sec Output*/
}