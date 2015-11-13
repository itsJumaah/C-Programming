/* Program written by Bilal Jumaah 12232659 */

#include <stdio.h>
int num, res; 
int fact(int input) {
	res=1;
	for(num=input; num>1; num--) {
		res=res*num;
	}
	return res;
}
int n, r, z, result;
int main() {
	printf("Hello and welcome to nCr calculator. ver1.0\nIt's based on the equation C(n,r)= (n)! / ((r)!x(n-r)!).\n\n");
	while(true) {
		printf("n=");
		scanf("%d", &n);
		if((n<1)||(n>12)) {
			printf("Error, you have entered a value outside the range 1 to 12.\n");
			continue;
		}
		else {
			break;
		}
	}
	while(true) {
		printf("r=");
		scanf("%d", &r);
		if((r<1)||(r>n)) {
			printf("Error, you have entered a value outside the range 1 to %d.\n", n);
			continue;
		}
		else {
			break;
		}
	}
	z=n-r;
	result = fact(n) / (fact(z)*fact(r)); 
	printf("C(%d,%d)=%d\n\n\n", n, r, result);
}
