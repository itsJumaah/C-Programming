#include <stdio.h>
int num1, num2;
int *ptr;
int main() {
  ptr = &num1;
  *ptr = 37;
  ptr = &num2;
  *ptr = 18;
  printf("num1 is %d and num2 is %d\n", num1, num2);
}